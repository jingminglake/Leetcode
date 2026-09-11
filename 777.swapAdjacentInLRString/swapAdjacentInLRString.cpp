#include <iostream>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.length() != end.length())
            return false;
        if (start == end)
            return true;
        string s, e;
        for (int i = 0; i < start.size(); i++) {
            if (start[i] != 'X')
                s += start[i];
            if (end[i] != 'X')
                e += end[i];
        }   
        if (s != e)
            return false;
        int sl = 0, sr = 0, el = 0, er = 0;
        for (int i = 0; i < start.size(); i++) {
            if (start[i] == 'L')
                sl++;
            if (end[i] == 'L')
                el++;
            if (start[i] == 'R')
                sr++;
            if (end[i] == 'R')
                er++;
            if (er > sr || sl > el)
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    string start = "RXXLRXRXL";
    string end = "XRLXXRRLX";
    cout << s.canTransform(start, end)<< endl;
    return 0;
}
