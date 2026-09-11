#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
   vector<int> getRow(int rowIndex) {
     vector<int> ans(rowIndex+1, 1);
     for (int i = 2; i <= rowIndex; i++) {
       for (int j = i-1; j >= 1; j--) {
	 ans[j] = ans[j-1] + ans[j];
       }
     }
     return ans;
   }
};

int main()
{
  Solution s;
  vector<int> vec = s.getRow(4);
  vector<int>::iterator it = vec.begin();
  while (it != vec.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
