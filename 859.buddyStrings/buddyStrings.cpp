#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        int len_A = A.length(), len_B = B.length();
        if (len_A != len_B)
            return false;
        if (A == B) {
            unordered_set<char> s(A.begin(), A.end());
            return s.size() < A.length();
        }
        int left_A = 0, right_A = len_A - 1;
        int left_B = 0, right_B = len_B - 1;
        while (left_A < len_A && A[left_A] == B[left_B]) {
            left_A++; left_B++;
        }
        while (right_A >= 0 && A[right_A] == B[right_B]) {
            right_A--; right_B--;
        }
        //cout << left_A << " " << right_A << " , " << left_B << " " << right_B << endl;
        if (left_A >= right_A || left_B >= right_B) {
            return false;
        } else if (A[left_A] == B[right_B] && A[right_A] == B[left_B]) {
            return A.substr(left_A + 1, right_A - left_A - 1) == B.substr(left_B + 1, right_B - left_B - 1);
        } else {
            return false;
        }
    }
};

int main() {
    Solution s;
    string A = "aba", B = "aba";
    cout << s.buddyStrings(A, B) << endl;
    return 0;
}
