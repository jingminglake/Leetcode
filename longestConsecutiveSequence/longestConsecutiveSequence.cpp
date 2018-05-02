#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums) {
            if (!m.count(num)) {
                int left = m.count(num - 1) ? m[num - 1] : 0;
                int right = m.count(num + 1) ? m[num + 1] : 0;
                int sum = left + right + 1;
                m[num] = sum;
                res = max (res, sum);
                m[num - left] = sum;
                m[num + right] = sum;
            }
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
