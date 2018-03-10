#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        if (chars.size() == 0)
            return res;
        chars[res++] = chars[0];
        int cur = chars[0];
        int count = 1;
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == cur)
                count++;
            else {
                if (count >= 2) {
                    string num = to_string(count);
                    for (char digit : num)
                        chars[res++] = digit;
                }
                cur = chars[i];
                chars[res++] = cur;
                count = 1;
            }
        }
        if (count > 1) {
            string num = to_string(count);
            for (char digit : num)
                chars[res++] = digit;
        }
        return res;
    }
};

int main()
{
  Solution s;
  vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  vector<char> chars2 = {'a'};
  vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
  cout << s.compress(chars1) << endl;
  cout << s.compress(chars2) << endl;
  cout << s.compress(chars3) << endl;
  return 0;
}
