#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Employee {
public:
    Employee(int _id, int _importance) : id(_id), importance(_importance) {
    
    }
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        if (employees.size() == 0)
            return 0;
        unordered_map<int, Employee*> m;
        for (Employee* e : employees) {
            m[e->id] = e;
        }
        return dfs(m, id);
    }
    int dfs(unordered_map<int, Employee*>& m, int id) {
        int res = m[id]->importance;
        for (int i = 0; i < m[id]->subordinates.size(); i++) {
            res += dfs(m, m[id]->subordinates[i]);       
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
