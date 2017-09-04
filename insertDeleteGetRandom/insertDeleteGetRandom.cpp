// clang++ validateIPAddress.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class RandomizedSet{
public:
  /** Initialize your data structure here. */
  RandomizedSet() {
    srand(time(0));  
  }
    
  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (m.find(val) != m.end())
      return false;
    nums.push_back(val);
    m.insert(make_pair(val, nums.size() - 1));
    return true;
  }
    
  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    unordered_map<int, int>::iterator it = m.find(val);
    if (it == m.end())
      return false;
    int last = nums.back();
    nums[m[val]] = last;
    m[last] = m[val];
    nums.pop_back();
    m.erase(val);
    return true;
  }
    
  /** Get a random element from the set. */
  int getRandom() {
    return nums[rand() % nums.size()];
  }
private:
  vector<int> nums;
  unordered_map<int, int> m; // num -> location
};

int main()
{
  RandomizedSet s;
  s.insert(1);
  s.insert(2);
  s.remove(2);
  cout << s.getRandom() << endl;
  s.insert(2);
  cout << s.getRandom() << endl;
  return 0;
}
