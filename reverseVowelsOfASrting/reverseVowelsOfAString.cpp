#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution{
public:
  string reverseString(string s) {
    int i = 0, j = s.length() - 1;
    if (i == j)
      return s;
    char vowel[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    unordered_set<char> set(vowel, vowel+10);
    
    while (i < j) {
      if (set.find(s[i]) == set.end()) {
	i++;
	continue;
      }
      if (set.find(s[j]) == set.end()) {
	j--;
	continue;
      }
      swap(s[i], s[j]);
      i++;
      j--;
    }
    return s;
  }
};

int main()
{
  Solution s;
  string str = "aA";
  cout << s.reverseString(str) << endl;
  return 0;
}
