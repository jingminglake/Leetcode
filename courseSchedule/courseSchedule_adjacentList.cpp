#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > neighbors(numCourses);
        vector<int> indegree(numCourses);
        for (auto& p : prerequisites) {
            neighbors[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            for (int neighbor_c : neighbors[course]) {
                if (--indegree[neighbor_c] == 0)
                    q.push(neighbor_c);
            }
        }
        return numCourses == count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> prerequisites;
    prerequisites.push_back({0,3});
    prerequisites.push_back({1,3});
    prerequisites.push_back({2,3});
    prerequisites.push_back({4,3});
    prerequisites.push_back({5,4});
    cout << s.canFinish(6, prerequisites);
    cout << endl;
    return 0;
}
