#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m;
        m.insert({'6', '9'});
        m.insert({'9', '6'});
        m.insert({'8', '8'});
        m.insert({'1', '1'});
        m.insert({'0', '0'});
        int left = 0, right = num.size() - 1;
        while (left <= right) {
            if (m.count(num[left]) && m[num[left]] == num[right]) {
                left++;right--;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    string num = "101";
    string num2 = "69";
    string num3 = "818";
    string num4 = "919";
    cout << s.isStrobogrammatic(num) << endl;
    cout << s.isStrobogrammatic(num2) << endl;
    cout << s.isStrobogrammatic(num3) << endl;
    cout << s.isStrobogrammatic(num4) << endl;
    return 0;
}
