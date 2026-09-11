class Solution {
    public boolean isBipartite(int[][] graph) {
        int nodeNum = graph.length;
        int[] color = new int[nodeNum]; // -1, 0, 1
        for (int i = 0; i < graph.length; i++) {
            if (color[i] == 0 && !dfs(i, color, -1, graph)) {
                return false;
            }
        }
        return true;
    }
    
    boolean dfs(int start, int[] color, int curColor, int[][] graph) {
        color[start] = curColor;
        for (int n : graph[start]) {
            if (color[n] == 0) {
                if (!dfs(n, color, -curColor, graph)) {
                    return false;
                }
            } else if (color[n] == curColor) {
                return false;
            }
        }
        return true;
    }
}
