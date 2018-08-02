#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int word_num = 0;
        int size = sentence.size();
        unordered_map<int, int> m; // start from index of word -> can fit how many words in one row
        for (int i = 0; i < rows; i++) {
            int start = word_num % size;
            if (!m.count(start)) {
                int len = 0;
                int num = 0;
                int index = start;
                while (len < cols) {
                    len += sentence[(index++) % size].length() + 1;
                    num++;
                    if (len - 1 > cols) {
                        num--;
                        break;
                    }
                }
                m[start] = num;
            }
            word_num += m[start];
        }
        return word_num / size;
    }
};

int main() {
    Solution s;
    int rows = 3, cols = 6;
    vector<string> sentence = {"a", "bcd", "e"};
    cout << s.wordsTyping(sentence, rows, cols) << endl;
    return 0;
}
