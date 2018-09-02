#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if (numRows == 0)
            return res;
        vector<int> pre_level = {1};
        res.push_back(pre_level);
        for (int i = 1; i < numRows; i++) {
            vector<int> level(i + 1, 1);
            for (int k = 1; k <= i - 1; k++) {
                level[k] = pre_level[k - 1] + pre_level[k];
            }
            res.push_back(level);
            pre_level = level;
        }
        return res;
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
