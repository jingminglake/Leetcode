#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int n = num.length(), drop = k;
        for (char c : num) {
            while (!res.empty() && (res.back() > c) && drop) {
                res.pop_back();
                drop--;
            }
            res.push_back(c);
        }
        res.resize(n - k);
        int pos = res.find_first_not_of('0');
        res.erase(0, pos);
        //res = res.substr(pos);
        if (res.empty())
            return "0";
        return res;
    }
};

int main() {
    Solution s;
    string num = "10200";
    int k = 1;
    cout << s.removeKdigits(num, k) << endl;
    return 0;
}
