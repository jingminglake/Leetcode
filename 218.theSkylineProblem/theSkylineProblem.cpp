#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Compare {
public:
    bool operator()(const pair<int, int>& v1, const pair<int, int>& v2) const {
        if (v1.first != v2.first)
            return v1.first < v2.first;
        else
            return v1.second > v2.second;
    }
};
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > res;
        vector<pair<int, int> > height;
        for (auto& b : buildings) {
            height.push_back({b[0], b[2]});
            height.push_back({b[1], -b[2]});
        }
        sort(height.begin(), height.end(), Compare());
        multiset<int> m;
        m.insert(0);
        int prev = 0;
        for (auto& h : height) {
            if (h.second >= 0) {
                m.insert(h.second);
            } else {
                m.erase(m.find(-h.second));
            }
            int cur = *m.rbegin();
            if (cur != prev) {
                res.push_back(make_pair(h.first, cur));
                prev = cur;
            }
        }
        return res;
    }
};

int main()
{
  Solution s;
  vector<vector<int>> buildings = {{2, 9, 10},
				    {3, 7, 15},
				    {5, 12, 12},
				    {15, 20, 10},
				    {19, 24, 8}};
  for (auto& p : s.getSkyline(buildings))
    cout << "(" << p.first << ", " << p.second << ") ";
  cout << endl;
  return 0;
}
