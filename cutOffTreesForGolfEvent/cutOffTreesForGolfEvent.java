class Solution {
    public int cutOffTree(List<List<Integer>> forest) {
        int res = 0;
        int m = forest.size(), n = forest.get(0).size();
        List<int[]> heights = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest.get(i).get(j) > 1) heights.add(new int[]{ forest.get(i).get(j), i, j });
            }
        }
        heights.sort((a, b) -> (a[0] - b[0]));
        int step = bfs(0, 0, heights.get(0)[1], heights.get(0)[2], forest, m, n);
        if (step == -1) return -1;
        res += step;
        for (int i = 0; i < heights.size() - 1; i++) {
            step = bfs(heights.get(i)[1], heights.get(i)[2], heights.get(i + 1)[1], heights.get(i + 1)[2], forest, m, n);
            if (step == -1) return -1;
            res += step;
        }
        return res;
    }
    
    public int bfs(int start_i, int start_j, int end_i, int end_j, List<List<Integer>> forest,
                  int m, int n) {
        int step = 0;
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {start_i, start_j});
        visited[start_i][start_j] = true;
        int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                int[] cur = q.poll();
                if (cur[0] == end_i && cur[1] == end_j) return step;
                for (int[] dir : dirs) {
                    int next_i = cur[0] + dir[0];
                    int next_j = cur[1] + dir[1];
                    if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) continue;
                    if (visited[next_i][next_j] || (forest.get(next_i).get(next_j) == 0)) continue;
                    q.add(new int[] {next_i, next_j});
                    visited[next_i][next_j] = true;
                }
            }
            step++;
        }
        return -1;
    }
}
