class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        for (int i = 0; i < equations.size(); i++) {
            List<String> equation = equations.get(i);
            if (!graph.containsKey(equation.get(0))) {
                graph.put(equation.get(0), new HashMap<>());
            }
            graph.get(equation.get(0)).put(equation.get(1), values[i]);
            if (!graph.containsKey(equation.get(1))) {
                graph.put(equation.get(1), new HashMap<>());
            }
            graph.get(equation.get(1)).put(equation.get(0), 1 / values[i]);
        }
        double[] res = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            if (!graph.containsKey(queries.get(i).get(0)) || !graph.containsKey(queries.get(i).get(1))) {
                res[i] = -1.0;
            } else {
                res[i] = dfs(graph, queries.get(i).get(0), queries.get(i).get(1), new HashSet<>());
            }
        }
        return res;
    }
    
    public double dfs(Map<String, Map<String, Double>> graph, String start, String end, Set<String> visited) {
        if (start.equals(end)) return 1;
        
        for (String neighbor : graph.get(start).keySet()) {
            if (!visited.contains(neighbor)) {
                visited.add(neighbor);
                double neighorRes = dfs(graph, neighbor, end, visited);
                if (neighorRes != -1.0) {
                    return graph.get(start).get(neighbor) * neighorRes;
                }
                visited.remove(neighbor);
            }
        }
        return -1;
    }
}
