#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0)
            return 0;
        int m = costs.size(), n = costs[0].size();
        int pre_min_cost = 0, pre_min_index = -1;
        int pre_second_min_cost = 0, pre_second_min_index = -1;
        for (int i = 0; i < m; i++) {
            int cur_min_cost = INT_MAX, cur_min_index = -1;
            int cur_second_min_cost = INT_MAX, cur_second_min_index = -1;
            for (int j = 0; j < n; j++) {
                int val = (j != pre_min_index ? pre_min_cost : pre_second_min_cost) + costs[i][j];
                if (val <= cur_min_cost) {
                    cur_second_min_cost = cur_min_cost;
                    cur_second_min_index = cur_min_index;
                    cur_min_cost = val;
                    cur_min_index = j;
                } else if (val < cur_second_min_cost) {
                    cur_second_min_cost = val;
                    cur_second_min_index = j;
                }
            }
            pre_min_cost = cur_min_cost;
            pre_min_index = cur_min_index;
            pre_second_min_cost = cur_second_min_cost;
            pre_second_min_index = cur_second_min_index;
        }
        return pre_min_cost;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > costs = {{17,2,17},
                                  {16,16,5},
                                  {14,3,19}};
    cout << s.minCostII(costs) << endl;
    return 0;
}
