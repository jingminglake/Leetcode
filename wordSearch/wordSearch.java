class Solution {
    public boolean exist(char[][] board, String word) {
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word.charAt(0)) {
                    if (dfs(board, word, 0, m, n, i, j)) return true;
                }
            }
        }
        return false;
    }
    
    private boolean dfs(char[][] board, String word, int level, int m, int n, int i, int j) {
        if (level == word.length()) {
            return true;
        }
        char c = word.charAt(level);
        if (i < 0 || i >= m || j < 0 || j >= n || c != board[i][j]) {
            return false;
        }
        board[i][j] = '#';
        boolean res = dfs(board, word, level + 1, m, n, i + 1, j)
            || dfs(board, word, level + 1, m, n, i - 1, j)
            || dfs(board, word, level + 1, m, n, i, j + 1)
            || dfs(board, word, level + 1, m, n, i, j - 1);
        board[i][j] = c;
        return res;
    }
}
