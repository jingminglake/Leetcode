#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        istringstream iss(input);
        string line;
        stack<int> s;
        s.push(0);
        while (getline(iss, line, '\n')) {
            int level = line.find_last_of('\t') + 1; // get cur level
            string name = line.substr(level);
            while (level < s.size() - 1)  // first  compare cur level with cur stack height
                s.pop();
            s.push(s.top() + name.length() + 1); // +1 for '/'
            if (name.find(".") != string::npos)
                res = max (res, s.top() - 1); // -1 for last '/'
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
    return 0;
}
