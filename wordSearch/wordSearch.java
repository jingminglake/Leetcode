class Solution {
    public boolean exist(char[][] board, String word) {
        char[] w = word.toCharArray();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (dfs(board, i, j, w, 0))
                    return true;
            }
        }
        return false;
    }
    private boolean dfs(char[][] board, int i, int j, char[] word, int depth) {
        if (depth == word.length)
            return true;
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word[depth])
            return false;
        char c = board[i][j];
        board[i][j] = '#';
        boolean exists = dfs(board, i, j + 1, word, depth + 1)
            || dfs(board, i + 1, j, word, depth + 1)
            || dfs(board, i, j - 1, word, depth + 1)
            || dfs(board, i - 1, j, word, depth + 1);
        board[i][j] = c;
        return exists;
    }
}
