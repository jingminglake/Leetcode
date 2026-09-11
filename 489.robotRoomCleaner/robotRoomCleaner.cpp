/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        vector<pair<int, int> > dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int d = 0; // 0: up, 1: left, 2: down, 3: right
        dfs (robot, visited, d, 1, 3, dirs);
    }
    void dfs(Robot& robot, unordered_set<string>& visited, int d, int i, int j, vector<pair<int, int> >& dirs) {
        string cur_pos = to_string(i) + "," + to_string(j);
        if (visited.count(cur_pos))
            return;
        visited.insert(cur_pos);
        robot.clean();
        for (int k = 0; k < 4; k++) {
            if (robot.move()) {
                int next_i = i + dirs[d].first;
                int next_j = j + dirs[d].second;
                dfs (robot, visited, d, next_i, next_j, dirs);
                // go back to starting position!
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            } // if
            // turn to next direction
            robot.turnLeft();
            d = (d + 1) % 4;
        }
    }
};
