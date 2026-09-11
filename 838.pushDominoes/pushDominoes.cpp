#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = "L" + dominoes + "R";
        int len = dominoes.length();
        int left = 0, right = 1;
        string res;
        while (right < len) {
            if (dominoes[right] == '.') {
                right++;
                continue;
            }
            if (left > 0)
                res += dominoes[left];
            int mid_len = right - left - 1;
            if (dominoes[right] == 'L') {
                if (dominoes[left] == 'L') {
                    res += string(mid_len, 'L');
                } else if (dominoes[left] == 'R') {
                    res += string(mid_len / 2, 'R') + string(mid_len % 2, '.') + string(mid_len / 2, 'L');
                }
            } else if (dominoes[right] == 'R') {
                if (dominoes[left] == 'L') {
                    res += string(mid_len, '.');
                } else if (dominoes[left] == 'R') {
                    res += string(mid_len, 'R');
                }
            }
            left = right;
            right++;
        }
        return res;
    }
};

int main() {
    Solution s;
    string dominoes = ".L.R...LR..L..";
    cout << s.pushDominoes(dominoes) << endl;
    return 0;
}
