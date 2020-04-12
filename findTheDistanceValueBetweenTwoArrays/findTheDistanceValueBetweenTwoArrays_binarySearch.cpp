class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        sort(arr2.begin(), arr2.end());
        for (int i = 0; i < arr1.size(); i++) {
            auto it1 = lower_bound(arr2.begin(), arr2.end(), arr1[i] - d);
            auto it2 = upper_bound(arr2.begin(), arr2.end(), arr1[i] + d);
            if (it1 == it2) res++;
        }
        return res;
    }
};
