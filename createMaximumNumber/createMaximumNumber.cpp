#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int m = nums1.size();
        int n = nums2.size();
        for (int i = max (0, k - n); i <= min (k, m); i++) {
            vector<int> v1 = maxNumberHelper(nums1, i);
            vector<int> v2 = maxNumberHelper(nums2, k - i);
            res = max (res, mergeVector(v1, v2) );
        }
        return res;
    }
    vector<int> maxNumberHelper(vector<int>& nums, int i) {
        vector<int> res;
        if (i <= 0)
            return res;
        int drop = nums.size() - i;
        for (int num : nums) {
            while (drop && res.size() && res.back() < num) {
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }
        res.resize(i);
        return res;
    }
    vector<int> mergeVector(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0)
            return nums2;
        if (n == 0)
            return nums1;
        vector<int> res(m + n);
        int i = 0, p1 = 0, p2 = 0;
        while (i < res.size()) {
            res[i++] = greater(nums1, p1, nums2, p2) ? nums1[p1++] : nums2[p2++];
        }
        return res;
    }
    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {3,4,6,5};
    vector<int> nums2 = {9,1,2,5,8,3};
    int k = 5;
    for(int n : s.maxNumber(nums1, nums2, k))
        cout << n << " ";
    cout << endl;
    return 0;
}
