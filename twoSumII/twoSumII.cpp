#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int size = numbers.size();
    vector<int> ans;
    int left = 0, right = size - 1;
    while (left < right) {
      if (numbers[left] + numbers[right] < target) {
	left++;
      }
      else if (numbers[left] + numbers[right] > target) {
	right--;
      }
      else {
	ans.push_back(left + 1);
	ans.push_back(right + 1);
	break;
      }	
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[4] = {2, 7, 11, 15};
  vector<int> vec(a,a+4);
  vector<int> ans = s.twoSum(vec, 9);
  vector<int>::iterator it = ans.begin();
  while (it != ans.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
