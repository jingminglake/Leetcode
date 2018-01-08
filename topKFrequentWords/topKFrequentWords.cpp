#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    vector<string> res;
    unordered_map<string, int> m;
    for (string& word : words)
      m[word]++;
    auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
      return a.second > b.second || (a.second == b.second && a.first < b.first);
    };
    typedef priority_queue<pair<string, int>, vector<pair<string, int> >, decltype(comp) > my_priority_queue;
    my_priority_queue pq(comp);
    for(auto w : m){
      pq.emplace(w.first, w.second);
      if(pq.size()>k) pq.pop();
    }
    while(!pq.empty()){
      res.push_back(pq.top().first);
      pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main()
{
  Solution s;
  vector<string> words1 = {"i", "love", "leetcode", "i", "love", "coding"};
  vector<string> words2 = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
  for (string& str : s.topKFrequent(words1, 2)) {
    cout << str << " ";
  }
  cout << endl;
  for (string& str : s.topKFrequent(words2, 4)) {
    cout << str << " ";
  }
  cout << endl;
}
