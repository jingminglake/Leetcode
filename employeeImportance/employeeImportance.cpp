#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Employee {
public:
  Employee(int _id, int _importance) : id(_id), importance(_importance) {
    
  }
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution{
public:
  int getImportance(vector<Employee*> employees, int id) {
    int res = 0;
    if (employees.empty())
      return res;
    unordered_map<int, Employee*> m;
    for (Employee *e : employees) {
      m.insert(make_pair(e->id, e));
    }
    if (!m[id])
      return res;
    unordered_set<int> s;
    queue<Employee*> q;
    q.push(m[id]);
    while (!q.empty()) {
      Employee *temp = q.front();
      q.pop();
      res += temp->importance;
      s.insert(temp->id);
      for (int id : temp->subordinates) {
	if (s.find(id) == s.end())
	  q.push(m[id]);
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  Employee n0(1,5), n1(2,3), n2(3,3);
  n0.subordinates.push_back(n1.id);
  n0.subordinates.push_back(n2.id);
  vector<Employee*> employees;
  employees.push_back(&n0);
  employees.push_back(&n1);
  employees.push_back(&n2);
  cout << s.getImportance(employees, n0.id) << endl;
  return 0;
}
