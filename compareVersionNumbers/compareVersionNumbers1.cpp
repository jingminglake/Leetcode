#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = split(version1);
        vector<string> v2 = split(version2);
        for (int i = 0; i < max ((int)v1.size(), (int)v2.size()); i++) {
            int i1 = i < v1.size() ? stoi(v1[i]) : 0;
            int i2 = i < v2.size() ? stoi(v2[i]) : 0;
            if (i1 < i2)
                return -1;
            else if (i1 > i2)
                return 1;
        }
        return 0;
    }
    vector<string> split(string s) {
        istringstream iss(s);
        vector<string> res;
        string temp;
        while (getline(iss, temp, '.')) {
            res.push_back(temp);
        }
        return res;
    }
};

int main() {
    Solution s;
    string version1 = "0.1", version2 = "1.1";
    cout << s.compareVersion(version1, version2) << endl;    
    return 0;
}
