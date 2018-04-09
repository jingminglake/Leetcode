#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        long n = points.size();
        long allPostive = 1;
        long crossProduct = 0;
        for (int i = 0; i < n; i++) {
            long dx1 = points[i][0] - points[(i + 1) % n][0];
            long dy1 = points[i][1] - points[(i + 1) % n][1];
            long dx2 = points[(i + 2) % n][0] - points[(i + 1) % n][0];
            long dy2 = points[(i + 2) % n][1] - points[(i + 1) % n][1];
            crossProduct = dx1 * dy2 - dx2 * dy1;
            if (i == 0) {
                if (crossProduct != 0)
                    allPostive = crossProduct > 0 ? 1 : -1;
            } else {
                if (allPostive * crossProduct < 0)
                    return false;
            }
        }
        return true;
    }
};

int main() {
  Solution s;
  vector<vector<int>> points = {{0,0},{0,10},{10,10},{10,0},{5,5}}; 
  cout << s.isConvex(points) << endl;
  return 0;
}
