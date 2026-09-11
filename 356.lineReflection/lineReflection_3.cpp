#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.size() == 0)
            return true;
        int leftM = points[0].first, rightM = points[0].first;
        unordered_map<int, unordered_set<int> > m;
        for (auto& p : points) {
            leftM = min (leftM, p.first);
            rightM = max (rightM, p.first);
            m[p.first].insert(p.second);
        }
        int64_t mid_2 = leftM + rightM;
        for (auto& p : points) {
            int x_ = mid_2 - p.first;
            if (!m.count(x_) || !m[x_].count(p.second))
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<pair<int, int> > points = {make_pair(1, 1), make_pair(-1, 1)};
    cout << s.isReflected(points) << endl;
    return 0;
}
