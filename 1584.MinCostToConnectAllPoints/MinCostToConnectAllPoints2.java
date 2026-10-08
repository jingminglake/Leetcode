class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0; // 从0开始建树
        boolean[] inTree = new boolean[n];
        int total = 0;

        for (int round = 0; round < n; round++) {
            int node = -1;
            for (int i = 0; i < n; i++) {
                if (inTree[i]) continue;
                if (node == -1 || dist[i] < dist[node]) node = i;
            }
            inTree[node] = true;
            total += dist[node];
            for (int v = 0; v < n; v++) {
                if (inTree[v]) continue;
                dist[v] = Math.min(dist[v], distance(points, node, v));
            }
        }
        return total;
    }

    private int distance(int[][] p, int u, int v) {
        return Math.abs(p[u][0] - p[v][0]) + Math.abs(p[u][1] - p[v][1]);
    }
}