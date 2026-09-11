#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        if (input.length() == 0)
            return res;
        istringstream iss(input);
        string line;
        unordered_map<int, int> m;
        m[-1] = 0;
        while (getline(iss, line, '\n')) {
            int level = line.find_last_of('\t')  + 1;
            string name = line.substr(level);
            int len = name.length();
            if (name.find(".") != string::npos) {
                res = max (res, m[level - 1] + len);
            } else {
                m[level] = m[level - 1] + len + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
    return 0;
}
