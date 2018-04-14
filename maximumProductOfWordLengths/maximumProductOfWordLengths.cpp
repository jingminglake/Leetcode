#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        long res = 0;
        vector<int> wordTag(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            int tag = 0;
            for (char c : words[i]) {
                tag |= 1 << (c - 'a');
            }
            wordTag[i] = tag;
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((wordTag[i] & wordTag[j]) == 0) {
                    res = max (res, (long) words[i].length() * (long) words[j].length());
                }
            }
        }
        return res;
    }
};

int main () {
    Solution s;
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << s.maxProduct(words) << endl;
    return 0;
}
