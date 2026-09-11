#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int res = 1;
        string A_ = A;
        while (A.length() < B.length()) {
            A += A_;
            res++;
        }
        if (A.find(B) != string::npos)
            return res;
        A += A_;
        res++;
        if (A.find(B) != string::npos)
            return res;
        return -1;
    }
};

int main()
{
    Solution s;
    string A = "abcd";
    string B = "cdabcdab";
    cout << s.repeatedStringMatch(A, B) << endl;
    return 0;
}
