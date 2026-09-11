#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
  vector<int> constructRectangle(int area) {
    vector<int> ans;
    for (int i = sqrt(area); i >= 1; i--) {
      int low = i, high = area;
      while (low <= high) {
	long long mid = low + (high-low)/2;	
	if (i * mid < area) {
	  low = mid + 1;
	} else if (i * mid > area) {
	  high = mid - 1;
	} else {
	  //ans.clear();
	  ans.push_back(mid);
	  ans.push_back(i);
	  return ans;
	}
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> vec = s.constructRectangle(9999998);
  for (int i : vec)
    cout << i << " ";
  cout << endl;
  return 0;
}
