class Solution {
public:
    bool rotateString(string A, string B) {
        if (A == B) return true;
        int len_A = A.length(), len_B = B.length();
        if (len_A != len_B) return false;
        for (int i = 0; i < len_B; i++) {
            if (B[i] == A[0] && checkHelper(A, B, 0, i)) return true;
        }
        return false;
    }
    bool checkHelper(string& A, string& B, int pA, int pB) {
        int len = A.length();
        for (int i = 0; i < len; i++) {
            if (pB >= len) pB = pB % len;
            if (A[pA] != B[pB]) return false;
            pA++; pB++;
        }
        return true;
    }
};
