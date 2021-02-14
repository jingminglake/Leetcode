class Solution {
    public boolean isBipartite(int[][] graph) {
        int[] colored = new int[graph.length]; // -1 => A, 0 => uncolored, 1 => B
        for (int node = 0; node < graph.length; node++) {
            if (colored[node] == 0 && !dfs(graph, node, 1, colored)) {
                return false;
            }
        }
        return true;
    }

    private boolean dfs(int[][] graph, int start, int color, int[] colored) {
        if (colored[start] != 0) {
            return colored[start] == color;
        }
        colored[start] = color;
        for (int neighbor : graph[start]) {
            if (!dfs(graph, neighbor, -color, colored)) {
                return false;
            }
        }
        return true;
    }
}
