// clang++ setMismatch.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> findErrorNums(vector<int>& nums) {
    vector<int> ans;
    int size = nums.size();
    vector<int> hash(size+1, 0);
    for (int i = 0; i < size; i++) {
      if (++hash[nums[i]] == 2)
	ans.push_back(nums[i]);
    }
    for (int i = 1; i < size+1; i++) {
      if (hash[i] == 0)
	ans.push_back(i);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> vec = {1,2,2,4};
  vector<int> res = s.findErrorNums(vec);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
