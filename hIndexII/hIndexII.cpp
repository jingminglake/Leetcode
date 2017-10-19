// clang++ hIndex.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int hIndex(vector<int>& citations) {
    int left=0, len = citations.size(), right= len-1,  mid;
    while(left<=right)
      {
	mid = left + (right - left) / 2;
	if(citations[mid] == (len-mid)) 
	  return citations[mid];
	else if(citations[mid] > (len-mid)) 
	  right = mid - 1;
	else 
	  left = mid + 1;
      }
    return len - (right + 1); 
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
