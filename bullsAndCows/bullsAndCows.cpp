// clang++ bullsAndCows.cpp -std=c++11

#include <iostream>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int hash1[10] = {0}, hash2[10] = {0};
        int bulls = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            hash1[secret[i] - '0']++;
            hash2[guess[i] - '0']++;
        }
        int same = 0;
        for (int i = 0; i < 10; i++)
            same += min (hash1[i], hash2[i]);
        return to_string(bulls) + "A" + to_string(same - bulls) + "B";
    }
};

int main()
{
    Solution s;
    string s1 = "1122";
    string s2 = "2211";
    cout << s.getHint(s1, s2);
    cout << endl;
    return 0;
}
