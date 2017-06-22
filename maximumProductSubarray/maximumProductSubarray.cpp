#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int maxProduct(vector<int>& nums) {
    int size = nums.size();
    int maxP = nums[0];
    int maxHere;
    int minHere;
    int minPrev = nums[0], maxPrev = nums[0];
    for (int i = 1; i < size; i++) {
      maxHere = max(max(maxPrev*nums[i], minPrev*nums[i]), nums[i]);
      minHere = min(min(maxPrev*nums[i], minPrev*nums[i]), nums[i]);
      maxP = max(maxP, maxHere);
      maxPrev = maxHere;
      minPrev = minHere;
    }
    return maxP;
  }
};

int main()
{
  Solution s;
  int a[4] = {2,3,-2,4};
  vector<int> vec(a, a+4);
  cout << s.maxProduct(vec);
  cout << endl;
  return 0;
}
