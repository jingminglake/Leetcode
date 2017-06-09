#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool wordPattern(string pattern, string str) {
    istringstream iss(str);
    string word;
    vector<string> strV;
    while(getline(iss, word, ' ')) {
      strV.push_back(word);
    }
    int pSize = pattern.size();
    int sSize = strV.size();
    if (pSize != sSize)
      return false;
    unordered_map<char, string> m1;
    unordered_map<string, char> m2;
    for (int i = 0; i < pSize; i++) {
      unordered_map<char, string>::iterator it1 = m1.find(pattern[i]);
      if (it1 == m1.end())
	m1.insert(make_pair(pattern[i], strV[i]));
      else if (it1->second != strV[i])
	return false;
      unordered_map<string, char>::iterator it2 = m2.find(strV[i]);
      if (it2 == m2.end())
	m2.insert(make_pair(strV[i], pattern[i]));
      else if (it2->second != pattern[i])
	return false;
      
    }
    return true;
  }
};

int main()
{
  Solution s;
  string pattern = "abba";
  string str = "dog dog dog dog";
  cout << s.wordPattern(pattern, str);
  cout << endl;
  return 0;
}
