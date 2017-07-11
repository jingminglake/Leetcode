#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > ans;
    unordered_map<string, vector<string> > m;
    for (string& str : strs) {
      //string key = str;
      //sort(key.begin(), key.end());
      cout << "str-->" << str << endl;
      string key = strSort(str);
      cout << "key-->" << key << endl;
      m[key].push_back(str);
    }
    unordered_map<string, vector<string> >::iterator it = m.begin();
    while (it != m.end()) {
      ans.push_back(it->second);
      ++it;
    }
    return ans;
  }

  string strSort(string& s) {
    string ss = "";
    int count[26] = {0};
    for (int i = 0; i < s.length(); i++) {
      count[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < count[i]; j++) {
 	ss += 'a' + i;
      }
    }
    return ss;
  }
};

int main()
{
  Solution s;
  string ss[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<string> vec(ss, ss+6);
  vector<vector<string> > res = s.groupAnagrams(vec);
  for (vector<string>& v : res) {
    for (string s : v)
      cout << s << " ";
    cout << endl;
  }
  return 0;
}
