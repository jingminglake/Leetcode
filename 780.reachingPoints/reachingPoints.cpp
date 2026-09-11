#include <iostream>
using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == ty) // could not move to next step
                break;
            if (tx > ty) {
                if (ty > sy)
                    tx %= ty;
                else // ty will not change in the future
                    return (tx - sx) % ty == 0; // tx must meet the pattern, else we return false
            } else {
                if (tx > sx)
                    ty %= tx;
                else
                    return (ty - sy) % tx == 0;
            }
        }
        return tx == sx && ty == sy;
    }
};

int main() {
    Solution s;
    int sx = 1, sy = 1, tx = 3, ty = 5;
    cout << s.reachingPoints(sx, sy, tx, ty) << endl;
    return 0;
}
