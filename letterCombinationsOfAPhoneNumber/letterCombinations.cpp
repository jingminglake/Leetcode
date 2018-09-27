#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.empty())
      return ans;
    ans.push_back("");
    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for(int i = 0; i < digits.size(); i++){
      string s = map[digits[i] - '0'];
      vector<string> temp;
      for(int j = 0; j < s.length(); j++){
	vector<string>::iterator it = ans.begin();
	while(it != ans.end()){
	  temp.push_back(*it + s[j]);
	  ++it;
	}
      }
      ans.swap(temp);
      temp.clear();
    }
    return ans;
  }
};


int main()
{
  Solution s;
  vector<string> ans = s.letterCombinations(string("234"));
  vector<string>::iterator it = ans.begin();
  while(it != ans.end()){
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
