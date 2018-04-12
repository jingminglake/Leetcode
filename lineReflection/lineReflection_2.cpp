#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class PairHash {
public:
     size_t operator()(const pair<int, int>& p) const {
        return p.first * 31 + p.second;
     }
};

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.size() == 0)
            return true;
        int leftM = INT_MAX, rightM = INT_MIN;
        unordered_set<pair<int, int>, PairHash> s;
        for (auto& p : points) {
            leftM = min (leftM, p.first);
            rightM = max (rightM, p.first);
            s.insert(p);
        }
        int mid = leftM + (rightM - leftM) / 2;
        for (auto& p : points) {
            pair<int, int> temp = make_pair(leftM + rightM - p.first, p.second);
            if (!s.count(temp))
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
