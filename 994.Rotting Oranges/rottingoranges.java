class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int freshCnt = 0;
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    freshCnt++;
                else if (grid[i][j] == 2)
                    q.add(new int[] {i, j});
            }
        }
        int minutes = 0;
        if (freshCnt == 0)
            return minutes; // no fresh at the begin
        boolean[][] visited = new boolean[m][n];
        int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int[] peek = q.poll();
                for (int[] dir : dirs) {
                    int nextI = peek[0] + dir[0];
                    int nextJ = peek[1] + dir[1];
                    if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n)
                        continue;
                    if (grid[nextI][nextJ] != 1 || visited[nextI][nextJ])
                        continue;
                    visited[nextI][nextJ] = true;
                    freshCnt--;
                    q.add(new int[] {nextI, nextJ});
                }
            }
            minutes++;
        }
        if (freshCnt == 0)
            return minutes - 1;
        else
            return -1;
    }
}