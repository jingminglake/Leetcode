#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {            
        while (!version1.empty() || !version2.empty()) {
            string v1, v2;
            if (version1.find_first_of(".") != string::npos) {
                v1 = version1.substr(0, version1.find_first_of("."));
                version1 = version1.substr(version1.find_first_of(".") + 1);
            } else {
                v1 = version1;
                version1 = "";
            }
            if (version2.find_first_of(".") != string::npos) {
                v2 = version2.substr(0, version2.find_first_of("."));
                version2 = version2.substr(version2.find_first_of(".") + 1);
            } else {
                v2 = version2;
                version2 = "";
            }
            //cout << version1 << " " << version2 << endl;
            //cout << v1 << "  "  << v2 << endl;
            long n1 = v1.empty() ? 0 : stol(v1);
            long n2 = v2.empty() ? 0 : stol(v2);
            if (n1 < n2)
                return -1;
            else if (n1 > n2)
                return 1;
        }
        return 0;
    }
};

int main() {
    Solution s;
    string version1 = "0.1", version2 = "1.1";
    cout << s.compareVersion(version1, version2) << endl;    
    return 0;
}
