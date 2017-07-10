#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  string frequencySort(string s) {
    string ans;
    int size = s.length();
    unordered_map<char, int> m;
    for (int i = 0; i < size; i++)
      m[s[i]]++;
    vector<vector<int> > bucket(size+1, vector<int>(0));
    unordered_map<char, int>::iterator it = m.begin();
    while (it != m.end()) {
      bucket[it->second].push_back(it->first);
      ++it;
    }
    for (int i = size; i > 0; i--) {
      for (int j = 0; j < bucket[i].size(); j++) {
	for (int k = i-1; k >= 0; k--) {
	  ans += bucket[i][j];
	}
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string ss = "tree";
  cout << s.frequencySort(ss);
  cout << endl;
  return 0;
}
