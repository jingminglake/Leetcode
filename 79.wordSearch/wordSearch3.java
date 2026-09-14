class Solution {
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        char startC = word.charAt(0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == startC) {
                    char tmp = board[i][j];
                    board[i][j] = '#';
                    boolean dRes = dfs(board, word, 0, i, j, dirs);
                    if (dRes) return true;
                    board[i][j] = tmp;
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, String word, int level, int i, int j, int[][] dirs) {
        if (level == word.length() - 1) {
            return true; 
        }
        
        for (int[] dir : dirs) {
            int nextI = dir[0] + i;
            int nextJ = dir[1] + j;
            if (nextI < 0 || nextI >= board.length || nextJ < 0 || nextJ >= board[0].length) continue;
            if (board[nextI][nextJ] != word.charAt(level + 1)) continue;
            if (board[nextI][nextJ] == '#') continue;
            char tmp = board[nextI][nextJ];
            board[nextI][nextJ] = '#';
            boolean dRes = dfs(board, word, level + 1, nextI, nextJ, dirs);
            if (dRes) return true;
            board[nextI][nextJ] = tmp;
        }
        return false;
    }
}