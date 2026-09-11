#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n, "");
        for (int i = 1; i <= n; i++) {
            int mod_3 = i % 3, mod_5 = i % 5;
            if (mod_3 && mod_5) {
                res[i - 1] = to_string(i);
            } else {
                if (mod_3 == 0)
                    res[i - 1] += "Fizz";
                if (mod_5 == 0)
                    res[i - 1] += "Buzz";
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> vec = s.fizzBuzz(20);
    for (string str : vec)
        cout << str << endl;
    return 0;
}
