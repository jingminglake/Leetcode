class Solution {
    public int numIslands(char[][] grid) {
        int res = 0;
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0' || visited[i][j])
                    continue;
                visited[i][j] = true;
                dfs(i, j, grid, visited);
                res++;
            }
        }
        return res;
    }

    // drawback: dfs need deep stack call
    private void dfs(int startI, int startJ, char[][] grid, boolean[][] visited) {
        int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int[] dir : dirs) {
            int nextI = startI + dir[0];
            int nextJ = startJ + dir[1];
            if (nextI < 0 || nextI >= grid.length || nextJ < 0 || nextJ >= grid[0].length)
                continue;
            if (grid[nextI][nextJ] == '0')
                continue;
            if (visited[nextI][nextJ])
                continue;
            visited[nextI][nextJ] = true;
            dfs(nextI, nextJ, grid, visited);
        }
    }
}