#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int strStr(string haystack, string needle) {
    int hSize = haystack.size();
    int nSize = needle.size();
    if (nSize > hSize)
      return -1;
    if (nSize == 0 || hSize == 0)
      return 0;
    vector<int> next = buildKmpNextArray(needle);
    for (int i : next) {
      cout << i << " ";
    }
    cout << endl;
    int i = 0, j = 0;
    while (i < hSize) {
      if (haystack[i] == needle[j]) {
	i++;
	j++;
      }
      if (j == nSize)
	return i - j;
      if (i < hSize && haystack[i] != needle[j]) {
	if (j)
	  j = next[j-1];
	else
	  i++;
      }
    }
    return -1;
  }
  vector<int> buildKmpNextArray(string& needle) {
    int size = needle.length();
    vector<int> next(size, 0);
    int i = 1, j = 0;
    while (i < size) {
      cout << i << " " << j << endl;
      if (needle[i] == needle[j]) {
	next[i] = j + 1;
	i++;
	j++;
      } else if (j != 0) {
	j = next[j-1];
      }
      else {
	next[i++] = 0;
      }
    }
    return next;
  }
};

int main()
{
  Solution s;
  string haystack = "babcabceabcabcabcaaa";
  string needle = "abcabcaaa";
  cout << s.strStr(haystack, needle) << endl;
  return 0;
}
