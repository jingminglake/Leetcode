#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len = machines.size();
        vector<int> preSum(len + 1, 0);
        for (int i = 0; i < len; i++) {
            preSum[i + 1] = preSum[i] + machines[i];
        }
        if (preSum[len] % len)
            return -1;
        int avg = preSum[len] / len;
        int res = 0;
        for (int i = 0; i < len; i++) {
            int left_need = i * avg - preSum[i];
            int right_need = (len - i - 1) * avg - (preSum[len] - preSum[i] - machines[i]);
            int moves = 0;
            if (left_need > 0 && right_need > 0)
                moves = left_need + right_need;
            else
                moves = max( abs(left_need), abs(right_need) );
            res = max (res, moves);
        }
        return res;
    }
};



int main()
{
    Solution sl;
    vector<int> machines = {1,0,5};
    cout << sl.findMinMoves(machines) << endl;
}
