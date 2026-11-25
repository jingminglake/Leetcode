class Solution {
    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.offer(new int[]{i, 0});
                visited[i][0] = true;
            }
            if (board[i][n - 1] == 'O') {
                q.offer(new int[]{i, n - 1});
                visited[i][n - 1] = true;
            }
        }
        for (int j = 1; j < n - 1; j++) {
            if (board[0][j] == 'O') {
                q.offer(new int[]{0, j});
                visited[0][j] = true;
            }
            if (board[m - 1][j] == 'O') {
                q.offer(new int[]{m - 1, j});
                visited[m - 1][j] = true;
            }
        }
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            for (int[] dir : dirs) {
                int nextI = p[0] + dir[0];
                int nextJ = p[1] + dir[1];
                if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n) continue;
                if (visited[nextI][nextJ] || board[nextI][nextJ] == 'X') continue;
                visited[nextI][nextJ] = true;
                q.offer(new int[]{nextI, nextJ});
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
    }
}