#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> m;
        m['M'] = 1000;
        m['D'] = 500;
        m['C'] = 100;
        m['L'] = 50;
        m['X'] = 10;
        m['V'] = 5;
        m['I'] = 1;
        for(int i = 0; i < s.length(); i++){
            ans += m[s[i]];
            if(i>0 && m[s[i]] > m[s[i-1]])
                ans -= 2*m[s[i-1]];
            //cout << ans << endl;
        }
    
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("MCDLXXVI") << endl;
    return 0;
}
