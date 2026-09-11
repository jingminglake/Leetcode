#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if (data.size() == 0)
            return false;
        int count = 0;
        for (int d : data) {
            if (count == 0) {
                if ((d >> 5) == 0b110)
                    count = 1;
                else if ((d >> 4) == 0b1110)
                    count = 2;
                else if ((d >> 3) == 0b11110)
                    count = 3;
                else if ((d >> 7) != 0b0)
                    return false;
            } else {
                if ((d >> 6) != 0b10) {
                    return false;
                }
                count--;
            }
        }
        return count == 0;
    }
};

int main() {
    Solution s;
    vector<int> data1 = {197, 130, 1};
    vector<int> data2 = {235, 140, 4};
    cout << s.validUtf8(data1) << endl;
    cout << s.validUtf8(data2) << endl;
    return 0;
}
