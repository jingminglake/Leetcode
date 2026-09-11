class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0;
        vector<vector<int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (char c : instructions) {
            if (c == 'R') {
                d = (d + 1) % 4;
            } else if (c == 'L') {
                d = (d + 3) % 4;
            } else {
                x += dirs[d][0]; y += dirs[d][1];
            }
        }
        return (x == 0 && y == 0) || d;
    }
};
