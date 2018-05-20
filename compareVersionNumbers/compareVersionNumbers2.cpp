#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int num1 = 0;
        int num2 = 0;
        while (i < version1.size() || j < version2.size()) {
            while (i < version1.size() && version1[i] != '.') {
                num1 = num1 * 10 + version1[i] - '0';
                i++;
            }
            while (j < version2.size() && version2[j] != '.') {
                num2 = num2 * 10 + version2[j] - '0';
                j++;
            }
            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;
            num1 = 0;
            num2 = 0;
            i++;
            j++;
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
