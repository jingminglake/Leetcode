class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res(arr.size(), -1);
        int curM = arr.back();
        for (int i = arr.size() - 2; i >= 0; i--) {
            res[i] = curM;
            curM = max(curM, arr[i]);
        }
        return res;
    }
};
