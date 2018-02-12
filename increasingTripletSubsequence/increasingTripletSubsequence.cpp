#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        int minV = INT_MAX, secondMinV = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= minV)
                minV = nums[i];
            else if (nums[i] <= secondMinV)
                secondMinV = nums[i];
            else
                return true;
        }
        return false;
  }
};

int main()
{
  Solution s;
  int a[6] = {6, 5, 6, 0, 1, 7};
  vector<int> vec(a, a+6);
  cout << s.increasingTriplet(vec);
  cout << endl;
  return 0;
}
