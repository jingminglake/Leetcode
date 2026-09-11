#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    int size = prices.size();
    if (size < 2)
      return ans;
    for (int i = 0; i < size - 1; i++) {
      if (prices[i+1] > prices[i])
	ans += prices[i+1] - prices[i];
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[7] = {2,6,4,8,10,9,15};
  vector<int> vec(a, a+7);
  cout << s.maxProfit(vec) << endl;
 
  return 0;
}
