class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 0 || cost.size() == 0) return -1;
        int tank = 0;
        int res = 0;
        int total = 0;
        for (int i = 0; i < cost.size(); i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                res = i + 1;
                tank = 0;
            }
            total += gas[i] - cost[i];
        }
        return total >= 0 ? res : -1;
    }
};
