#include <iostream>
using namespace std;
class Solution {
public:
    string similarRGB(string color) {
        return "#" + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) + helper(color.substr(5, 2));
    }
    string helper(string str) {
        string dec_to_hex = "0123456789abcdef";
        string res = "";
        int dec_num = stoi(str, nullptr, 16);
        int c0 = dec_num / 17;
        int c1 = dec_num % 17;
        if (c1 > 8)
            c0 = c0 + 1;
        res = res + dec_to_hex[c0] + dec_to_hex[c0];
        return res;
    }
};

int main() {
  Solution s;
  cout << s.similarRGB("#09f166") << endl;
  return 0;
}
