#include <iostream>
using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        for (int i = 2; i <= N; i++) {
            if (isValid(i))
                res++;
        }
        return res;
    }
    bool isValid(int N) {
        bool res = false;// false, unless there are at least one 2,5,6,9
        while (N > 0) {
            int digit = N % 10;
            if (digit == 3 || digit == 4 || digit == 7)
                return false;
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                res = true;
            N /= 10;
        }
        return res;
    }
};

int main() {
  Solution s;
  cout << s.rotatedDigits(100) << endl;
  return 0;
}
