#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1])
                nums[res++] = nums[i];
        }
        return res;
    }
};

int main()
{
  Solution s;
  int a[5] = {1,1,2,4,5};
  vector<int> vec(a, a+5);
  int size = s.removeDuplicates(vec);
  for (int i = 0; i < size; i++)
      cout << vec[i] << " ";
  cout << endl;
  return 0;
}
