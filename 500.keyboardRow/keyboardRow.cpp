#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<string> findWords(vector<string>& words) {
    vector<string> ans;
    char one[10] = {'q','w','e','r','t','y','u','i','o','p'};
    char two[9] = {'a','s','d','f','g','h','j','k','l'};
    char three[7] = {'z','x','c','v','b','n','m'};
    unordered_set<char> rowOne(one, one+10);
    unordered_set<char> rowTwo(two, two+9);
    unordered_set<char> rowThree(three, three+7);
    vector<unordered_set<char> > rows;
    rows.push_back(rowOne);
    rows.push_back(rowTwo);
    rows.push_back(rowThree);
    for (string word : words) {
      if (word.empty())
	continue;
      char firstChar = tolower(word[0]);
      int k = 0;
      for (k = 0; k < 3; k++) {
	if (rows[k].find(firstChar) != rows[k].end())
	  break;
      }
      char nextChar;
      bool isValid = true;
      for (int i = 1; i < word.length(); i++) {
	nextChar = tolower(word[i]);
	if (rows[k].find(nextChar) == rows[k].end()) {
	  isValid = false;
	  break;
	}
      }
      if (isValid) {
	ans.push_back(word);
      }
    }
    
    return ans;
  }
};

int main()
{
  Solution s;
  string a[4] = {"Hello", "Alaska", "Dad", "Peace"};
  vector<string> vec(a,a+4);
  vector<string> ans = s.findWords(vec);
  for (string s : ans) {
     cout << s << " ";
  }
  cout << endl;
  return 0;
}
