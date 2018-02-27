#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        if (num.size() == 0)
            return false;
        unordered_map<char, char> m;
        m.insert(make_pair('6', '9'));
        m.insert(make_pair('9', '6'));
        m.insert(make_pair('8', '8'));
        m.insert(make_pair('1', '1'));
        m.insert(make_pair('0', '0'));
        int left = 0, right = num.size() - 1;
        while (left <= right) {
            if (!m.count(num[left]) || !m.count(num[right]))
                return false;
            else if (m[num[left]] != num[right])
                return false;
            left++;
            right--;
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
