#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n; i++) {
            while (!s.empty() && nums[i % n] > nums[s.top()]) {
                res[s.top()] = nums[i % n];
                s.pop();
            }
            if (i < n)
                s.push(i);
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[3] = {1,2,1};
    vector<int> vec(a, a+3);
    vector<int> res = s.nextGreaterElements(vec);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
