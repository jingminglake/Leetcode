#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        string word;
        int pSize = pattern.size();
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        int i = 0;
        for (string word; iss >> word; i++) {
            if (i == pSize || m1[pattern[i]] != m2[word])
                return false;
            m1[pattern[i]] = m2[word] = i + 1;
        }
        return i == pSize;
    }
};

int main()
{
    Solution s;
    string pattern = "abba";
    string str = "dog dog dog dog";
    cout << s.wordPattern(pattern, str);
    cout << endl;
    return 0;
}
