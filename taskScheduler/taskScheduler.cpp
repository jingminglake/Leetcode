#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int leastInterval(vector<char>& tasks, int n) {
    int size = tasks.size();
    int hash[26] = {0};
    int maxTaskCount = 0;
    for (char c : tasks) {
      hash[c-'A']++;
      maxTaskCount = max(maxTaskCount, hash[c-'A']);
    }
    int ans = (maxTaskCount - 1) * (n + 1);
    for (int i = 0; i < 26; i++)
      if (hash[i] == maxTaskCount)
	ans++;
    ans = max(size, ans);
    return ans;
  }
};

int main()
{
  Solution s;
  char a[6] = {'A','A','A','B','B','B'};
  vector<char> vec(a, a+6);
  cout << s.leastInterval(vec, 2);
  cout << endl;
  return 0;
}
