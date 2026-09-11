#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> vec(n, "");
        for (int i = 1; i <= n; i++) {
            vec[i - 1] = to_string(i);
        }
        while (n > 1) {
            for (int i = 0; i < n; i++) {
                vec[i] = "(" + vec[i] + "," + vec[n - i - 1] + ")";
            }
            n /= 2;
        }
        return vec[0];
    }
};

int main() {
  Solution s;
  cout << s.findContestMatch(8) << endl;
  return 0;
}
