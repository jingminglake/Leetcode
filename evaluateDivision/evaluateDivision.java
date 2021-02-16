class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, Map<String, Double>> graph = new HashMap<>();
        for (int i = 0; i < values.length; i++) {
            if (!graph.containsKey(equations.get(i).get(0))) {
                graph.put(equations.get(i).get(0), new HashMap<>());
            }
            if (!graph.containsKey(equations.get(i).get(1))) {
                graph.put(equations.get(i).get(1), new HashMap<>());
            }
            graph.get(equations.get(i).get(0)).put(equations.get(i).get(1), values[i]);
            graph.get(equations.get(i).get(1)).put(equations.get(i).get(0), 1 / values[i]);
        }
        double[] res = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            String start = queries.get(i).get(0);
            String end = queries.get(i).get(1);
            if (!graph.containsKey(start) || !graph.containsKey(end)) {
                res[i] = -1.0;
            } else {
                res[i] = dfs(start, end, graph, new HashSet<>());
            }
        }
        return res;
    }
    
    private double dfs(String start, String end, Map<String, Map<String, Double>> graph, Set<String> visited) {
        if (visited.contains(start)) return -1.0;
        if (start.equals(end)) return 1.0;
        visited.add(start);
        Map<String, Double> pairs = graph.get(start);
        double res = -1.0;
        for (String neighbor : pairs.keySet()) {
            if (!visited.contains(neighbor)) {
                res = dfs(neighbor, end, graph, visited);
                if (res != -1.0) {
                    return res * pairs.get(neighbor);
                }
            }
        }
        return res;
    }
}
