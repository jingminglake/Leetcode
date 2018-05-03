#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        bool res = false;
        if (nums.size() == 0)
            return res;
        vector<double> vec(nums.begin(), nums.end());
        dfs(vec, res);
        return res;
    }
    void dfs(vector<double> vec, bool& res) {
        if (res)
            return;
        if (vec.size() == 1 && abs(vec[0] - 24) < 1e-4) {
            res = true;
            return;
        }
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                double p = vec[i], q = vec[j];
                vector<double> temp{p + q, p - q, q - p, p * q};
                if (p > 0)
                    temp.push_back(q / p);
                if (q > 0)
                    temp.push_back(p / q);
                vector<double> next;
                for (int k = 0; k < vec.size(); k++) {
                    if (k != i && k != j)
                        next.push_back(vec[k]);
                }
                for (double d : temp) {
                    next.push_back(d);
                    dfs (next, res);
                    next.pop_back();
                }
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,5,5,5};
    cout << s.judgePoint24(nums) << endl;
    return 0;
}
