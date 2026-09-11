#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution{
public:
  int distributeCandies(vector<int>& candies) {
    unordered_set<int> kinds;
    for (int kind : candies) {
      kinds.insert(kind);
    }
    return min(kinds.size(), candies.size()/2);
  }
};

int main()
{
  Solution s;
  int a[6] = {1, 1, 2, 2, 3, 3};
  vector<int> vec(a,a+6);
  cout << s.distributeCandies(vec) << endl;
  return 0;
}
