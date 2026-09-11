#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long lowerbound = lower;
        for (int num : nums) {
            if (num == lowerbound) {
                lowerbound++;
            } else if (num > lowerbound) {
                if (num == lowerbound + 1) {
                    res.push_back(to_string(lowerbound));
                } else {
                    string s = to_string(lowerbound) + "->" + to_string(num - 1);
                    res.push_back(s);
                }
                lowerbound = (long)num + 1;
            }
        }
        if (lowerbound == upper)
            res.push_back(to_string(upper));
        else if (lowerbound < upper) {
            string s = to_string(lowerbound) + "->" + to_string(upper);
            res.push_back(s);
        }
        return res;
    }
};

int main() {
  Solution s;
  vector<int> nums = {0, 1, 3, 50, 75}; 
  for (string& ss : s.findMissingRanges(nums, 0, 99))
    cout << ss << " ";
  cout << endl;
  return 0;
}
