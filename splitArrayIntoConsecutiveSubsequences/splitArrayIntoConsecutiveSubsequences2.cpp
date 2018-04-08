// clang++ splitArrayIntoConsecutiveSubsequences2.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freqM, tailM;
        for (int num : nums)
            freqM[num]++;
        for (int num : nums) {
            if (freqM[num] == 0)
                continue;
            else if (tailM[num] > 0) {
                --tailM[num];
                ++tailM[num + 1];
            } else if (freqM[num + 1] > 0 && freqM[num + 2] > 0) {
                --freqM[num + 1];
                --freqM[num + 2];
                ++tailM[num + 3];
            } else {
                return false;
            }
            freqM[num]--;
        }
        return true;
    }
};

int main()
{
  Solution s;
  vector<int> nums = {1,2,3,4,4,5};
  cout << s.isPossible(nums);
  cout << endl;
  return 0;
}
