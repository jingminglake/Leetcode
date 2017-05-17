#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  string convert(string s,int numRows){
    string ans;
    int size = s.length();
    vector<string> vec(numRows, "");
    bool flag = true;
    int i = 0;
    while (i < size) {
      if (flag) {
	for(int j = 0; j < numRows; j++) {
	  if(i < size)
	    vec[j] += s[i];
	  i++;
	}
	//cout << "i-->" << i << endl;
      }
      else {
	for(int j = numRows - 2; j >= 1; j--) {
	  if(i < size)
	    vec[j] += s[i];
	  i++;
	}
      }
      flag = !flag;
    }//for
    vector<string>::iterator it = vec.begin();
    while (it != vec.end()) {
      ans += *it;
      cout << "vec-->" << *it << endl;
      ++it;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string ss = "ABCDE";
  cout << s.convert(ss, 3) << endl;
  return 0;
}
