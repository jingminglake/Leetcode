class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int n : arr2) m[n] = 0;
        for (int n : arr1) {
            if (m.count(n))
                m[n]++;
        }
        for (int n : arr2) {
            for (int i= 0; i < m[n]; i++) res.push_back(n);
        }
        vector<int> remain;
        for (int n : arr1) {
            if (!m.count(n)) remain.push_back(n);
        }
        sort(remain.begin(), remain.end());
        res.insert(res.end(), remain.begin(), remain.end());
        return res;
    }
};
