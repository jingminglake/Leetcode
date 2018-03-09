#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0)
            return res;
        vector<vector<int> > m(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for (auto& p : prerequisites) {
            m[p.second].push_back(p.first);
            indegree[p.first]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            res.push_back(node);
            for (int neighbor : m[node]) {
                if (--indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        if (count != numCourses)
            res.clear();
        return res;
    }
};

int main()
{
  Solution s;
  vector<pair<int, int> > prerequisites;
  prerequisites.push_back(make_pair(1,0));
  prerequisites.push_back(make_pair(2,0));
  prerequisites.push_back(make_pair(3,1));
  prerequisites.push_back(make_pair(3,2));
  vector<int> res = s.findOrder(4, prerequisites);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
