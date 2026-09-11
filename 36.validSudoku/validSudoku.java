class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] rows = new boolean[9][9];
        boolean[][] cols = new boolean[9][9];
        boolean[][] cube = new boolean[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '0' - 1;
                    int cube_id = i / 3 * 3 + j / 3; 
                    if (rows[i][digit] || cols[j][digit] || cube[cube_id][digit])
                        return false;
                    else {
                        rows[i][digit] = cols[j][digit] = cube[cube_id][digit] = true;
                    }
                }
            }
        }
        return true;
    }
}
