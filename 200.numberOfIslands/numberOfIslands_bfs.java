class Solution {
    public int numIslands(char[][] grid) {
        int res = 0;
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    bfs(grid, visited, i, j, m, n);
                    res++;
                }
            }
        }
        return res;
    }
    
    public void bfs(char[][] grid, boolean[][] visited, int i, int j, int m, int n) {
        Queue<int[]> q = new LinkedList<>();
        visited[i][j] = true;
        q.offer(new int[]{i, j});
        int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            for (int[] dir : dirs) {
                int next_i = p[0] + dir[0];
                int next_j = p[1] + dir[1];
                if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || grid[next_i][next_j] == '0'
                    || visited[next_i][next_j]) continue;
                visited[next_i][next_j] = true;
                q.offer(new int[]{next_i, next_j});
            }
        }
    }
}
