#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int romanToInt(string s) {
    int ans = 0;
    unordered_map<char, int> m;
    m.insert(unordered_map<char, int>::value_type('M', 1000));
    m.insert(unordered_map<char, int>::value_type('D', 500));
    m.insert(unordered_map<char, int>::value_type('C', 100));
    m.insert(unordered_map<char, int>::value_type('L', 50));
    m.insert(unordered_map<char, int>::value_type('X', 10));
    m.insert(unordered_map<char, int>::value_type('V', 5));
    m.insert(unordered_map<char, int>::value_type('I', 1));
    unordered_map<char, int>::iterator it1, it2;
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
