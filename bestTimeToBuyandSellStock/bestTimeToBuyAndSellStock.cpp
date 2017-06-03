#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    int size = prices.size();
    int minPrice = INT_MAX;
    for (int i = 0; i < size; i++) {
      if (prices[i] < minPrice)
	minPrice = prices[i];
      else if (prices[i] - minPrice > ans)
	ans = prices[i] - minPrice;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[6] = {7, 1, 5, 3, 6, 4};
  vector<int> vec(a, a+6);
  cout << s.maxProfit(vec) << endl;
  return 0;
}
