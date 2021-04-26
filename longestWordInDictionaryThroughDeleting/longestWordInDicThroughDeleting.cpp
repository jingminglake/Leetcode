#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string &s1, string &s2) {
                if (s1.length() == s2.length()) {
                    return s1 < s2;
                } else {
                    return s1.length() > s2.length();
                } });
        for (string &word : d) {
            if (canbeFormedByS(s, word))
                return word;
        }
        return "";
    }
    bool canbeFormedByS(string &s, string &word) {
        int wordSize = word.length();
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (j < wordSize && s[i] == word[j])
                j++;
            if (j == wordSize)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    string s1 = "abpcplea";
    vector<string> dic = {"ale", "apple", "monkey", "plea"};
    cout << s.findLongestWord(s1, dic);
    cout << endl;
    return 0;
}
