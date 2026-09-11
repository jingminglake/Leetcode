#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> m;
        for (int i = 0; i < position.size(); i++)
            m[-position[i]] = (target - position[i]) * 1.0 / speed[i];
        int res = 0;
        double cur_max = 0.0;
        for (auto& p : m) {
            if (p.second > cur_max) {
                cur_max = p.second;
                res++;
            }
        }
        return res;
    }
};

int main() {
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    int target = 12;
    Solution s;
    cout << s.carFleet(target, position, speed) << endl;
    return 0;
}
