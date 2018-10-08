#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
          vector<string> letter2morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> s;
        for (auto word : words) {
            string code;
            for (char c : word) 
                code += letter2morse[c - 'a'];
            s.insert(code);
        }
        return s.size();
    }
};

int main () {
    Solution s;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << s.uniqueMorseRepresentations(words) << endl;
    return 0;
}
