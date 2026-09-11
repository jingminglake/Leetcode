// clang++ LFUCache.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
public:
  LFUCache(int capacity) {
    this->capacity = capacity;
  }
  int get(int key) {
    unordered_map<int, pair<int, int> >::iterator it = m.find(key);
    if (it == m.end()) { // if not exist
      return -1;
    } else {
      // increase frequence
      freq[it->second.second].erase(iter[key]);
      it->second.second++;
      freq[it->second.second].push_back(key);
      iter[key] = --freq[it->second.second].end();
      if (freq[minFreq].size() == 0)
	++minFreq;
      return it->second.first;
    }
  }
  void put(int key, int value) {
    if (capacity <= 0)
      return;
    if (get(key) != -1) { //exists
      m[key].first = value;
      return;
    }
    if (m.size() >= capacity) { // not exists and need to replace
      m.erase(freq[minFreq].front());
      freq[minFreq].pop_front();
    }
    // after replace, insert
    m[key] = {value, 1};
    freq[1].push_back(key);
    iter[key] = --freq[1].end();
    minFreq = 1;
  }
private:
  unordered_map<int, pair<int, int> > m; // key ->{value, frequence}
  unordered_map<int, list<int> > freq; // frequnce -> (key1, key2...)
  unordered_map<int, list<int>::iterator> iter;//key -> (index1, index2...)
  int capacity;
  int minFreq;
};

int main()
{
  LFUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;       // returns 1
  cache.put(3, 3);    // evicts key 2
  cout << cache.get(2) << endl;       // returns -1 (not found)
  cout << cache.get(3) << endl;       // returns 3.
  cache.put(4, 4);    // evicts key 1.
  cout << cache.get(1) << endl;       // returns -1 (not found)
  cout << cache.get(3) << endl;       // returns 3
  cout << cache.get(4) << endl;       // returns 4
  return 0;
}
