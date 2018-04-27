#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        unordered_map<int, int> m;
        int num = 0, n = sentence.size();
        for (int i = 0; i < rows; i++) {
            int start = num % n;
            if (!m.count(start)) {
                int len = 0;
                int index = start;
                while (len <= cols) {
                    len += sentence[(index++) % n].length() + 1;
                    if (len - 1 == cols) {
                        index++;
                        break;
                    }
                }
                m[start] = index - start - 1;
                //cout << start << "-=-=-=" << index - start - 1 << endl;
            }
            num += m[start];
        }
        return num / n;
    }
};

int main() {
    Solution s;
    int rows = 3, cols = 6;
    vector<string> sentence = {"a", "bcd", "e"};
    cout << s.wordsTyping(sentence, rows, cols) << endl;
    return 0;
}
