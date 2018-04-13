#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double res = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = j; k < n; k++) {
                    int abx = points[j][0] - points[i][0];
                    int aby = points[j][1] - points[i][1];
                    int acx = points[k][0] - points[i][0];
                    int acy = points[k][1] - points[i][1];
                    double area = 0.5 * abs(abx * acy - aby * acx);
                    res = max (res, area);
                }
            }
        }
        return res;
    }
};

int main() {
  Solution s;
  vector<vector<int> > points = {{0,0}, {0,1}, {1,0}, {0,2}, {2,0}};
  cout << s.largestTriangleArea(points) << endl;
  return 0;
}
