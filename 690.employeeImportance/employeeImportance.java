/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        if (employees == null || employees.size() == 0)
            return 0;
        Map<Integer, Employee> m = new HashMap<>();
        for (Employee e : employees)
            m.put(e.id, e);
        return dfs(m, id);
    }
    int dfs(Map<Integer, Employee> m, int id) {
        int res = m.get(id).importance;
        for (int sub : m.get(id).subordinates)
            res += dfs(m, sub);
        return res;
    }
}
