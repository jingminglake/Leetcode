#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int leastInterval(vector<char>& tasks, int n) {
    int res = 0;
    unordered_map<char, int> m;
    int maxN = 1;
    for (char c : tasks)
      maxN = max (maxN, ++m[c]);
    int num = 0;
    for (auto& p : m) {
      if (p.second == maxN)
	num++;
    }
    return max ( (int)tasks.size(), (maxN - 1) * (n + 1) + num );
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
