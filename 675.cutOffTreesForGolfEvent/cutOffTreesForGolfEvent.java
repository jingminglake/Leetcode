class Solution {
    public int cutOffTree(List<List<Integer>> forest) {
        int m = forest.size(), n = forest.get(0).size();
        List<int[]> path = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest.get(i).get(j) > 1) {
                    path.add(new int[] {forest.get(i).get(j), i, j});
                }
            }
        }
        if (path.size() == 0) return 0;
        path.sort((a, b) -> a[0] - b[0]);
        
        int step = bfs(0, 0, path.get(0)[1], path.get(0)[2], forest, m, n);
        if (step == -1) return -1;
        int res = step;
        for (int i = 0; i < path.size() - 1; i++) {
            step = bfs(path.get(i)[1], path.get(i)[2], path.get(i + 1)[1], path.get(i + 1)[2], forest, m, n);
            if (step == -1) return -1;
            res += step;
        }
        return res;
    }
    
    private int bfs(int start_i, int start_j, int end_i, int end_j, List<List<Integer>> forest, int m, int n) {
        int res = 0;
        if (start_i == end_i && start_j == end_j) return res;
        boolean[][] visited = new boolean[m][n];
        int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[] {start_i, start_j});
        visited[start_i][start_j] = true;
        while (!q.isEmpty()) {
            int q_size = q.size();
            res++;
            for (int i = 0; i < q_size; i++) {
                int[] cur = q.poll();
                for (int[] dir : dirs) {
                    int next_i = cur[0] + dir[0];
                    int next_j = cur[1] + dir[1];
                    if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) continue;
                    if (next_i == end_i && next_j == end_j) return res;
                    if (visited[next_i][next_j] || forest.get(next_i).get(next_j) == 0) continue;
                    q.offer(new int[]{next_i, next_j});
                    visited[next_i][next_j] = true;
                }
            }
        }
        return -1;
    }
}
