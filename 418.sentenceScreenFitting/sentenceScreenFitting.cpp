#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int size = sentence.size();
        int index = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < rows; i++) {
            int start_index = index % size;
            if (!m.count(start_index)) {
                m[start_index] = rowFitting(sentence, cols, start_index);
            }
            index += m[start_index];
        }
        return index / size;
    }
    int rowFitting(vector<string>& sentence, int cols, int start) {
        int res = 0, len = 0, size = sentence.size();
        while (len < cols) {
            len += sentence[start++ % size].length() + 1;
            res++;
            if (len - 1 > cols) {
                res--;
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int rows = 3, cols = 6;
    vector<string> sentence = {"a", "bcd", "e"};
    cout << s.wordsTyping(sentence, rows, cols) << endl;
    return 0;
}
