class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        } else if (board[click[0]][click[1]] != 'E') {
            return board;
        }
        int m = board.length, n = board[0].length;
        int[][] dirs = {{-1, -1}, {-1, 0}, {-1, 1},
                        {0, -1}, {0, 1},
                        {1, -1}, {1, 0}, {1, 1}};
        int num = getAdjMineNum(board, click[0], click[1], dirs, m, n);
        if (num > 0) {
            board[click[0]][click[1]] = (char)('0' + num);
            return board;
        }
        Queue<int[]> q = new LinkedList<>();
        q.offer(click);
        board[click[0]][click[1]] = 'B';
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int[] dir : dirs) {
                int next_i = cur[0] + dir[0];
                int next_j = cur[1] + dir[1];
                if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) continue;
                if (board[next_i][next_j] == 'E') {
                    num = getAdjMineNum(board, next_i, next_j, dirs, m, n);
                    if (num > 0) {
                        board[next_i][next_j] = (char)('0' + num);
                    } else {
                        board[next_i][next_j] = 'B';
                        q.offer(new int[] {next_i, next_j});
                    }
                }
            }
        }
        return board;
    }
    
    private int getAdjMineNum(char[][] board, int i, int j, int[][] dirs, int m, int n) {
        int num = 0;
        for (int[] dir : dirs) {
            int next_i = i + dir[0];
            int next_j = j + dir[1];
            if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) continue;
            if (board[next_i][next_j] == 'M') num++;
        }
        return num;
    }
}
