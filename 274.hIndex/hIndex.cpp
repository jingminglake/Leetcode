// clang++ hIndex.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int hIndex(vector<int>& citations) {
    int ans = 0;
    int size = citations.size();
    vector<int> hash(size+1, 0);
    for (int i = 0; i < size; i++) {
      if (citations[i] > size)
	hash[size]++;
      else
	hash[citations[i]]++;
    }
    int sum = 0;
    for (int i = size; i >= 0; i--) {
      sum += hash[i];
      if (sum >= i) {
	ans = i;
	break;
      }
    }
    return ans;
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
