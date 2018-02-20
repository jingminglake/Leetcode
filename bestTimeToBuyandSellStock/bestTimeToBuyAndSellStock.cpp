#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int maxProfit(vector<int>& prices) {
    int res = 0;
    if (prices.size() < 2)
      return 0;
    int minP = INT_MAX;
    for (int price : prices) {
      minP = min (minP, price);
      res = max (res, price - minP);
    }
    return res;
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
