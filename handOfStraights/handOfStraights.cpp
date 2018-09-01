#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n % W)
            return false;
        map<int, int> m;
        for (int h : hand)
            m[h]++;
        for (auto& p : m) {
            if (p.second <= 0)
                continue;
            for (int i = 1; i < W; i++) {
                if (m.count(p.first + i)) {
                    m[p.first + i] -= p.second;
                    if (m[p.first + i] < 0)
                        return false;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    int W = 2;
    cout << s.isNStraightHand(hand, W) << endl;
    return 0;
}
