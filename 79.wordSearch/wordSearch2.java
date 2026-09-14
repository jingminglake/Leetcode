class Solution {
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        char startC = word.charAt(0);
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == startC) {
                    visited[i][j] = true;
                    boolean dRes = dfs(board, word, 0, i, j, visited, dirs);
                    if (dRes) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, String word, int level, int i, int j, boolean[][] visited, int[][] dirs) {
        if (level == word.length() - 1) {
            return true; 
        }
        
        for (int[] dir : dirs) {
            int nextI = dir[0] + i;
            int nextJ = dir[1] + j;
            if (nextI < 0 || nextI >= board.length || nextJ < 0 || nextJ >= board[0].length) continue;
            if (board[nextI][nextJ] != word.charAt(level + 1)) continue;
            if (visited[nextI][nextJ]) continue;
            visited[nextI][nextJ] = true;
            boolean dRes = dfs(board, word, level + 1, nextI, nextJ, visited, dirs);
            if (dRes) return true;
            visited[nextI][nextJ] = false;
        }
        return false;
    }
}