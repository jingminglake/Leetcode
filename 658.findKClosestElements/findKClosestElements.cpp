#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if (arr.size() == 1) { 
            res.push_back(arr[0]);
            return res;
        }
        int left = 0, right = arr.size() - k;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= x) {
                right = mid;
            } else if (arr[mid + k - 1] <= x) {
                left = mid;
            } else if (x - arr[mid] > arr[mid + k - 1] - x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        int resIndex = abs(arr[left] - x) <= abs(arr[right + k - 1] - x) ? left : right;
        for (int i = resIndex; i < resIndex + k; i++)
            res.push_back(arr[i]);
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
