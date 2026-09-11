#include <iostream>
#include <stack>
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
        stack<int> s;
        s.push(0);
        while (getline(iss, line, '\n')) {
            int level = line.find_last_of('\t') + 1;
            int len = line.length() - level;
            while (level + 1 < s.size()) {
                s.pop();
            }
            if (line.find('.') != string::npos) {
                res = max (res, s.top() + len);
            } else {
                s.push(s.top() + len + 1);
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
