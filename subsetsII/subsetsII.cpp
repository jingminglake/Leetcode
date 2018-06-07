#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        vector<int> subset;
        genSubsets(nums, 0, subset, ans);
        return ans;
    }
    void genSubsets(vector<int>& nums, int level, vector<int>& subset, vector<vector<int> >& ans) {
        if (level == nums.size()) {
            ans.push_back(subset);
            return;
        }
   
        subset.push_back(nums[level]);
        genSubsets(nums, level + 1, subset, ans);
        subset.pop_back();

        while (level + 1 < nums.size() && nums[level + 1] == nums[level])
            level++;
        genSubsets(nums, level + 1, subset, ans);
    }
};

int main()
{
    Solution s;
    int a[3] = {1,2,2};
    vector<int> vec(a, a+3);
    vector<vector<int> > res = s.subsetsWithDup(vec);
    vector<vector<int> >::iterator it = res.begin();
    while (it != res.end()) {
        for (int i : *it)
            cout << i << " ";
        cout << endl;
        ++it;
    }
    return 0;
}
