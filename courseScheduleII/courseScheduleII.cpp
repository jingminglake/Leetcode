#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
    vector<int> res;
    vector<vector<int> > adj(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++) {
      int curCourse = prerequisites[i].first;
      int preCourse = prerequisites[i].second;
      indegree[curCourse]++;
      adj[preCourse].push_back(curCourse);
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
      res.push_back(course);
      count++;
      for (int i = 0; i < adj[course].size(); i++) {
	if (--indegree[adj[course][i]] == 0)
	  q.push(adj[course][i]);
      }
    }//while
    
    if(count != numCourses) {
      res.clear();
    }
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
