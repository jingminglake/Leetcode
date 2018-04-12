#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.size() == 0)
            return true;
        int leftM = INT_MAX, rightM = INT_MIN;
        unordered_set<string> s;
        for (auto& p : points) {
            leftM = min (leftM, p.first);
            rightM = max (rightM, p.first);
            s.insert(to_string(p.first) + "," + to_string(p.second));
        }
        int mid = leftM + (rightM - leftM) / 2;
        for (auto& p : points) {
            string temp = to_string(leftM + rightM - p.first) + "," + to_string(p.second); 
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
