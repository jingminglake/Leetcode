#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();
    if (size < 1)
      return false;
    for (int i = 0; i < size; i++) {
      if (i == 0) {
	if (flowerbed[i] == 0 && flowerbed[i+1] == 0) {
          n--;
	  flowerbed[i] = 1;
	}
      }
      if (i == size-1) {
	if (flowerbed[i] == 0 && flowerbed[i-1] == 0) {
	  n--;
          break;
	}  
      }
      // cout << "---" << i << "---" << flowerbed[i] << endl;
      if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
	n--;
	flowerbed[i] = 1;
      }
    }
    return n <= 0 ? true : false;
  }
};

int main()
{
  Solution s;
  int a[8] = {0,1,0,1,0,1,0,0};
  vector<int> vec(a,a+8);
  cout << s.canPlaceFlowers(vec, 2) << endl;
  return 0;
}
