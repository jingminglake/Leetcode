#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res;
        if (k <= 0)
            return res;
        for (int i = max(k - n2, 0); i <= min(k, n1); i++) {
            vector<int> vec1 = getNDigitsMax(nums1, i);
            vector<int> vec2 = getNDigitsMax(nums2, k - i);
            res = max (res, mergeVector(vec1, vec2));
        }
        return res;
    }
    vector<int> getNDigitsMax(vector<int>& nums, int n) {
        int drop = nums.size() - n;
        vector<int> s;
        for (int num : nums) {
            while (!s.empty() && drop && num > s.back()) {
                drop--;
                s.pop_back();
            }
            s.push_back(num);
        }
        s.resize(n);
        return s;
    }
    vector<int> mergeVector(vector<int>& vec1, vector<int>& vec2) {
        int n1 = vec1.size(), n2 = vec2.size();
        vector<int> res(n1 + n2);
        int index = 0, p1 = 0, p2 = 0;
        while (p1 < n1 && p2 < n2) {
            res[index++] = greater(vec1, p1, vec2, p2) ? vec1[p1++] : vec2[p2++];
        }
        while (p1 < n1) {
            res[index++] = vec1[p1++];
        }
        while (p2 < n2) {
            res[index++] = vec2[p2++];
        }
        return res;
    }
    bool greater(vector<int>& vec1, int p1, vector<int>& vec2, int p2) {
        while (p1 < vec1.size() && p2 < vec2.size() && vec1[p1] == vec2[p2]) {
            p1++; p2++;
        }
        return p2 == vec2.size() || (p1 < vec1.size() && vec1[p1] > vec2[p2]);
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
