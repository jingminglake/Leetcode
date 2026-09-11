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
    int min = prices[0], max = prices[0];
    for (int i = 1; i < size; i++) {
      while (prices[i] < min) {
	min = prices[i];
	if (i == size - 1)
	  break;
	else
	  i++;
      }
      max = prices[i];
      if (i == size - 1) {
	//cout << "----" << max << " " << min << endl;
	ans += max - min;
	break;
      }
      else
	i++;
      while (prices[i] > max) {
	max = prices[i];
	if (i == size - 1)
	  break;
	else
	  i++;
      }
      //cout << "i:" << i << endl;
      cout << max << " " << min << endl;
      ans += max - min;
      if (i < size) {
        min = prices[i];
        max = prices[i];
	cout << "price: " << prices[i] << endl;
	//cout << "i:" << i << endl;
      }
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
