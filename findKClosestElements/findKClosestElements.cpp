#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if (arr.size() == 0)
            return res;
        int left = 0, right = arr.size() - 1;
        while (right - left + 1 > k) {
            if (arr[right] - x >= x - arr[left])
                right--;
            else
                left++;
        }
        res.assign(arr.begin() + left, arr.begin() + left + k);
        return res;
    }
};

int main()
{
  Solution s;
  vector<int> nums = {1,2,3,4,5};
  for (int n : s.findClosestElements(nums, 4, 3))
    cout << n << " ";
  cout << endl;
  return 0;
}
