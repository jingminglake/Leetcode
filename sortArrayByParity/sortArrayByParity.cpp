class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res = A;
        int lastOdd = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0) {
                swap(res[lastOdd++], res[i]);
            }
        }
        return res;
    }
};
