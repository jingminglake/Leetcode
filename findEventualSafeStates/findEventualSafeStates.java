class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> res = new ArrayList<>();
        int nodeCount = graph.length;
        int[] status = new int[nodeCount]; // 0 -> unvisited, 1 -> visited, 2 -> safe, 3 -> unsafe
        for (int i = 0; i < nodeCount; i++) {
            if (dfs(graph, i, status) == 2) {
                res.add(i);
            }
        }
        return res;
    }

    public int dfs(int[][] graph, int startNode, int[] status) {
        if (status[startNode] == 2 || status[startNode] == 3) {
            return status[startNode];
        }
        status[startNode] = 1;
        for (int neighbor : graph[startNode]) {
            if (status[neighbor] == 1 || dfs(graph, neighbor, status) == 3) {
                return status[startNode] = 3;
            }
        }
        return status[startNode] = 2;
    }
}