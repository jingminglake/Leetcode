#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        if (points.size() < 3)
            return res;
        unordered_map<int64_t, int> m;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (j == i)
                    continue;
                int dist_x = points[j].first - points[i].first;
                int dist_y = points[j].second - points[i].second;
                int64_t dist = dist_x * dist_x + dist_y * dist_y;
                m[dist]++;
            }
            for (auto& p : m) {
                res += p.second * (p.second - 1);
            }
            m.clear();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int> > vec;
    vec.push_back(make_pair(0,0));
    vec.push_back(make_pair(1,0));
    vec.push_back(make_pair(2,0));
    cout << s.numberOfBoomerangs(vec);
    cout << endl;
    return 0;
}
