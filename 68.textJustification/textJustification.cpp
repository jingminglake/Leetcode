#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int index = 0;
        while (index < words.size()) {
            int lineLen = words[index].length();
            int last = index + 1;
            while (last < words.size()) {
                if (words[last].length() + lineLen + 1 > maxWidth)
                    break;
                lineLen += words[last].length() + 1;
                last++;
            }
            int numOfWords = last - index;
            string line = words[index];
            if (last == words.size() || numOfWords == 1) {
                for (int i = index + 1; i < last; i++) {
                    line += " " + words[i];
                }
                lineLen = line.length();
                for (int i = lineLen; i < maxWidth; i++)
                    line += " ";
            } else {
                int spaceNum = (maxWidth - lineLen) / (numOfWords - 1);
                int r = (maxWidth - lineLen) % (numOfWords - 1);
                for (int i = index + 1; i < last; i++) {
                    for (int k = spaceNum; k >= 0; k--)
                        line += " ";
                    if (r > 0) {
                        line += " ";
                        r--;
                    }
                    line += words[i];
                }
            }
            res.push_back(line);
            index = last;
        }
        return res;
    }
};

int main()
{
  Solution s;
  vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
  for(string& ss : s.fullJustify(words, 16))
    cout << ss << endl;
  return 0;
}
