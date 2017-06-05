#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
   vector<vector<int> > generate(int numRows) {
     vector<vector<int> > ans;
     if (numRows < 1)
       return ans;
     vector<int> prev(1,1);
     ans.push_back(prev);
     for (int i = 1; i < numRows; i++) {
       vector<int> temp(i+1,1);
       for (int j = 1; j < i; j++) {
	 temp[j] = ans[i-1][j-1] + ans[i-1][j];
       }
       ans.push_back(temp);
       //prev.swap(temp);
     }
     return ans;
   }
};

int main()
{
  Solution s;
  vector<vector<int> > vec = s.generate(5);
  vector<vector<int> >::iterator it = vec.begin();
  while (it != vec.end()) {
    for (int i : *it)
      cout << i << " ";
    cout << endl;
    ++it;
  }
  return 0;
}
