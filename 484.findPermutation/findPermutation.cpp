#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res(s.length() + 1, 0);
        for (int i = 0; i < s.length() + 1; i++) {
            res[i] = i + 1;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'D') {
                int j = i;
                while (i < s.length() && s[i] == 'D')
                    i++;
                reverse(res.begin() + j, res.begin() + i + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string ss = "DIDDIIID";
    for (int n : s.findPermutation(ss))
        cout << n << " ";
    cout << endl;
    return 0;
}
