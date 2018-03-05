#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) {
            if (m.count(num))
                continue;
            unordered_map<int, int>::iterator it1 = m.find(num - 1), it2 = m.find(num + 1); 
            if (it1 == m.end() && it2 != m.end()) {
                m[num] = m[num + it2->second] = it2->second + 1;
            } else if (it1 != m.end() && it2 == m.end()) {
                m[num] = m[num - it1->second] = it1->second + 1;
            } else if (it1 != m.end() && it2 != m.end()) {
                m[num] = m[num + it2->second] =  m[num - it1->second] = it1->second + it2->second + 1;
            } else {
                m[num] = 1;
            }
        }
        int res = 0;
        for (auto& p : m) {
            res = max (res, p.second);
        }
        return res;
    }
};

int main()
{
  Solution s;
  vector<int> vec = {100, 4, 200, 1, 3, 2};
  cout << s.longestConsecutive(vec) << endl;
  return 0;
}
