// clang++ hIndexII.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int hIndex(vector<int>& citations) {
    int left = 0, right = citations.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (citations[mid] >= citations.size() - mid) {
	right = mid - 1;
      } else {
	left = mid + 1;
      }
    }
    return citations.size() - left;
  }
};

int main()
{
  Solution s;
  vector<int> vec = {0,1,3,5,6};
  cout << s.hIndex(vec);
  cout << endl;
  return 0;
}
