#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> m(26, 0);
        int count = 0;
        for (char c : licensePlate) {
            if (isalpha(c)) {
                m[tolower(c) - 'a']++;
                count++;
            }
        }
        string res;
        int minLen = INT_MAX;
        for (string& word : words) {
            if ((int)word.size() >= minLen)
                continue;
            vector<int> tempM = m;
            int tempC = count;
            for (char c : word) {
                if (--tempM[tolower(c) - 'a'] >= 0) {
                    tempC--;
                }
            }
            //cout << tempC << endl;
            if (tempC == 0) {
                res = word;
                minLen = word.size();
            }
        }
        return res;
    }
};

int main() {
  Solution s;
  string licensePlate = "1s3 PSt";
  vector<string> words = {"step", "steps", "stripe", "stepple"};
  cout << s.shortestCompletingWord(licensePlate, words) << endl;
  return 0;
}
