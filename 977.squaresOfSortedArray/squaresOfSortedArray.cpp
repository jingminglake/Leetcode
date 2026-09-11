class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size(), 0);
        int i = A.size() - 1;
        int left = 0, right = A.size() - 1;
        while (left <= right) {
            if (abs(A[left]) < abs(A[right])) {
                res[i--] = A[right] * A[right];
                right--;
            } else {
                res[i--] = A[left] * A[left];
                left++;
            }
        }
        return res;
    }
};
