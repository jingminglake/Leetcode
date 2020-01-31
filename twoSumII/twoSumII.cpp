#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum > target) { 
                right--;
            } else if (sum < target) {
                left++;
            } else {
                res = {left + 1, right + 1};
                break;
            }
        }
        return res;
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
