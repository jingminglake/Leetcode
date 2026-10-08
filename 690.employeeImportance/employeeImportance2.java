/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> idToEmployee = new HashMap<>();
        for (Employee e : employees) {
            idToEmployee.put(e.id, e);
        }
        Map<Integer, Integer> idToImportance = new HashMap<>();
        return dfs(idToEmployee, id, idToImportance);
    }

    private int dfs(Map<Integer, Employee> idToEmployee, int id, Map<Integer, Integer> m) {
        if (m.containsKey(id)) return m.get(id);
        
        Employee e = idToEmployee.get(id);
        int importance = e.importance;
        for (Integer subEId : e.subordinates) {
            importance += dfs(idToEmployee, subEId, m);
        }
        m.put(e.id, importance);
        return importance;
    }
}