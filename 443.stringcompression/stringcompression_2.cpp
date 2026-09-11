#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int i = 0;
        while (i < chars.size()) {
            char cur = chars[i];
            int cnt = 0;
            while (i < chars.size() && chars[i] == cur) {
                i++; cnt++;
            }
            chars[index++] = cur;
            if (cnt >= 2) {
                for (char c : to_string(cnt)) chars[index++] = c;
            }
        }
        return index;
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
