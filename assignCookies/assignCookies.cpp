#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    int ans = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = g.size()-1 , j = s.size()-1;
    while (i >= 0 && j >= 0) {
      if (g[i] <= s[j]) {
	ans++;
	i--;
	j--;
      } else {
	i--;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[3] = {1,2};
  int b[4] = {1,2,3};
  vector<int> vec1(a, a+2);
  vector<int> vec2(b, b+3);
  cout << s.findContentChildren(vec1, vec2);
  cout << endl;
  return 0;
}
