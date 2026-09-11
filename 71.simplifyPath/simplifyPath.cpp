#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution{
public:
  string simplifyPath(string path) {
    string ans;
    int size = path.length();
    istringstream iss(path);
    string temp;
    vector<string> vec;
    while (getline(iss, temp, '/')) {
      if (temp == "" || temp == ".") {
	continue;
      } else if (temp == "..") {
	if (!vec.empty())
	  vec.pop_back();
      } else {
	vec.push_back(temp);
      }
    }
    for (string ss : vec)
      ans += "/" + ss;
    return ans == "" ? "/" : ans;
  }
};

int main()
{
  Solution s;
  string path = "/..";
  cout << s.simplifyPath(path);
  cout << endl;
  return 0;
}
