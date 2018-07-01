#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    class PairHash {
    public:
        size_t operator()(const pair<int, int>& p) const {
            return p.first * 31 + p.second; 
        }
    };
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.size() == 0)
            return true;
        unordered_set<pair<int, int>, PairHash> s;
        int left_bound = INT_MAX, right_bound = INT_MIN;
        for (auto& p : points) {
            left_bound = min (left_bound, p.first);
            right_bound = max (right_bound, p.first);
            s.insert(p);
        }
        for (auto& p : points) {
            if (!s.count({left_bound + right_bound - p.first, p.second}))
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
