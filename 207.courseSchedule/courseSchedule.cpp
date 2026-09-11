#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > matrix(numCourses, vector<int>(numCourses,0));
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int curCourse = prerequisites[i].first;
            int preCourse = prerequisites[i].second;
            if (matrix[preCourse][curCourse] == 0)
                indegree[curCourse]++;
            matrix[preCourse][curCourse] = 1;
        }
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            for (int i = 0; i < numCourses; i++) {
                if (matrix[course][i] != 0) {
                    if (--indegree[i] == 0)
                        q.push(i);
                }
            }
        }//while
        return count == numCourses;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(0,3));
    prerequisites.push_back(make_pair(1,3));
    prerequisites.push_back(make_pair(2,3));
    prerequisites.push_back(make_pair(4,3));
    prerequisites.push_back(make_pair(5,4));
    cout << s.canFinish(6, prerequisites);
    cout << endl;
    return 0;
}
