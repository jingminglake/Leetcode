#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if (arr.size() == 0)
            return res;
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            //if (x > arr[mid]) {
                if (x - arr[mid] > arr[mid + k] - x)
                    left = mid + 1;
                else
                    right = mid;
            //} else {
            //    right = mid - 1;
            //}
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
