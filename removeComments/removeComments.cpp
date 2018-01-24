#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> res;
    bool commentFlag1 = false;  // //
    bool commentFlag2 = false;  // /**/
    string temp = "";
    for (string& s : source) {
      int i = 0;
      commentFlag1 = false;
      while (i < s.length()) {
	if (commentFlag1) {
	  break;
	} else if (commentFlag2) {                   
	  if (s[i] == '*') {
	    if (i + 1 < s.length() && s[i + 1] == '/') {
	      commentFlag2 = false;
	      i += 2;
	      continue;
	    }
	  }
	  i++;
	} else {
	  if (s[i] == '/') {
	    if (i + 1 < s.length() && s[i + 1] == '/') {
	      commentFlag1 = true;
	      i += 2;
	      continue;
	    } else if (i + 1 < s.length() && s[i + 1] == '*') {
	      commentFlag2 = true;
	      i += 2;
	      continue;
	    }
	  }
	  temp += s[i];
	  i++;
	}
      } // while
      if (!temp.empty() && (temp.find_first_not_of("") != string::npos) && !commentFlag2) {
	res.push_back(temp);
	temp = "";
      }
    }// for 
    return res;
  }
};

int main()
{
  Solution s;
  vector<string> comments = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}" };
  for (string ss : s.removeComments(comments)) {
    cout << ss << endl;
  }
  return 0;
}
