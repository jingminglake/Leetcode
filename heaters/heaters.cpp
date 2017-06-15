#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int size1 = houses.size();
    int size2 = heaters.size();
    int radius = 0;
    for (int i = 0; i < size1; i++) {
      int left = 0, right = size2-1;
      int flag = true;
      while (left <= right) {
	int mid = left + (right-left)/2;
	if (heaters[mid] > houses[i])
	  right = mid - 1;
	else if (heaters[mid] < houses[i])
	  left = mid + 1;
	else {
	  flag = false;
	  break;
	}
      }//while
      if (flag) {
	if (left > size2 - 1 && right >= 0)
	  radius = max(radius, abs(houses[i] - heaters[right]));	  
	else if (left <= size2 - 1 && right < 0)
	  radius = max(radius, abs(heaters[left] - houses[i]));
	else if (left <= size2 - 1 && right >= 0)
	  radius = max(radius, min(abs(heaters[left] - houses[i]), abs(houses[i] - heaters[right])));
      }
    }//for
    return radius;
  }
};

int main()
{
  Solution s;
  int a[8] = {282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
  int b[10] = {823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
  vector<int> vec1(a, a+8);
  vector<int> vec2(b, b+10);
  cout << s.findRadius(vec1, vec2) << endl;
  return 0;
}
