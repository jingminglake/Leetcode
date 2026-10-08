class Solution {
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        List<int[]> edges = new ArrayList<>(); // {dist, i, j}
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.add(new int[]{dist(points, i, j), i, j});
            }
        }
        edges.sort((a, b) -> Integer.compare(a[0], b[0]));

        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;

        int total = 0;
        int used = 0;
        for (int[] e : edges) {
            int pI = find(e[1]);
            int pJ = find(e[2]);
            if (pI == pJ) continue; // 已经连通了，选了成环
            parent[pI] = pJ;
            total += e[0];
            if (++used == n - 1) break; // n-1 条边就够了
        }
        return total;
    }

    private int[] parent;
    private int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    private int dist(int[][] p, int i, int j) {
        return Math.abs(p[i][0] - p[j][0]) + Math.abs(p[i][1] - p[j][1]);
    }
}