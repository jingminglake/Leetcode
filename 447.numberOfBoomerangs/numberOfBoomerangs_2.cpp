#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> m;
            for (int j = 0; j < points.size(); j++) {
                if (i == j)
                    continue;
                double dist = getDist(points[i], points[j]);
                m[dist]++;
            }
            for (auto& p : m) {
                res += (p.second - 1) * p.second;
            }
        }
        return res;
    }
    double getDist(pair<int, int>& p1, pair<int, int>& p2) {
        int64_t d_x = p1.first - p2.first;
        int64_t d_y = p1.second - p2.second;
        return sqrt(d_x * d_x + d_y * d_y); 
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
