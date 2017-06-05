#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
     vector<vector<int> > ans;
     vector<int> temp;
     int cc = nums.size();
     if (cc < 1)
       return nums;
     int rr = nums[0].size();
     if (cc * rr != r * c)
       return nums;
     for (int i = 0; i < nums.size(); i++) {
       for (int j = 0; j < nums[i].size(); j++) {
	 temp.push_back(nums[i][j]);
	 if (temp.size() == c) {
	   ans.push_back(temp);
	   temp.clear();
	 } 
       }
     }
     return ans;
   }
};

int main()
{
  Solution s;
  int a[2] = {1,2};
  int b[2] = {3,4};
  vector<int> v1(a,a+2);
  vector<int> v2(b,b+2);
  vector<vector<int> > nums;
  nums.push_back(v1);
  nums.push_back(v2);
  vector<vector<int> > vec = s.matrixReshape(nums, 1, 4);
  vector<vector<int> >::iterator it = vec.begin();
  while (it != vec.end()) {
    for (int i : *it)
      cout << i << " ";
    cout << endl;
    ++it;
  }
  return 0;
}
