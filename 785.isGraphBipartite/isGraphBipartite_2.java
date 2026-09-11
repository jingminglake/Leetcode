class Solution {
    public boolean isBipartite(int[][] graph) {
        int[] colored = new int[graph.length]; // -1 -> groupA; 0 -> unvisited; 1 -> groupB
        for (int i = 0; i < graph.length; i++) {
            if (colored[i] == 0 && !dfs(graph, 1, colored, i)) {
                return false;
            }
        }
        return true;
    }
    
    public boolean dfs(int[][] graph, int goingToColor, int[] colored, int cur) {
        if (colored[cur] != 0) {
            return goingToColor == colored[cur];
        }
        colored[cur] = goingToColor;
        for (int neighbor : graph[cur]) {
            if (!dfs(graph, -goingToColor, colored, neighbor)) {
                return false;
            }
        }
        return true;
    }
}
