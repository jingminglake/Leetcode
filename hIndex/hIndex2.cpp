// clang++ hIndex2.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int hIndex(vector<int>& citations) {
    int res = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i < citations.size(); i++) {
      if (citations[i] > i)
	res++;
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> vec = {3,0,6,1,5};
  cout << s.hIndex(vec);
  cout << endl;
  return 0;
}
