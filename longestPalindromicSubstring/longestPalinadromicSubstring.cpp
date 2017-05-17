#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string lp;
    int size = s.length();
    bool L[size][size];
    //vector<vector<bool> > L(size, vector<bool>(size, false));
    memset(L, false, size*size*sizeof(bool));
    for(int k = 0; k < size; k++)
      L[k][k] = true;
    for (int j = 1; j < size; j++)
      for (int i = 0; i < size - j; i++) {
	if (i + 1 < i + j - 1)
	  L[i][i + j] = L[i + 1][i + j - 1] && (s[i] == s[i + j]);
	else
	  L[i][i + j] = (s[i] == s[i + j]);
      }
    int low = 0, max = 1;
    for(int i = 0; i < size; i++)
      for(int j = i; j < size; j++){
	if(L[i][j] == true){
	  if(j - i + 1 > max) {
	    low = i;
	    max = j - i + 1;
	  }
	  //	  cout << "true-->" << i << " " << j << endl;
	}
      }
    //   cout << low << " " << high << " " << max << endl;
    lp = s.substr(low, max);
    return lp;
  }
};


int main()
{
  Solution s;
  string ss = "cbbd";
  cout << s.longestPalindrome(ss) << endl;
  return 0;
}
