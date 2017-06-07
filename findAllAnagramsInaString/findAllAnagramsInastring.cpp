#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    if (s.empty() || p.empty())
      return ans;
    int hash[256] = {0};
    int pSize = p.length();
    for (int i = 0; i < pSize; i++) {
      hash[p[i]]++;
    }
    int left = 0, right = 0, count = pSize;
    while (right < s.length()) {
      if (hash[s[right++]]-- >= 1)
	count--;
      if (count == 0)
	ans.push_back(left);
      if (right - left == pSize && hash[s[left++]]++ >= 0)
	count++;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string ss = "abab";
  string p = "ab";
  vector<int> ans = s.findAnagrams(ss, p);
  vector<int>::iterator it = ans.begin();
  while (it != ans.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
