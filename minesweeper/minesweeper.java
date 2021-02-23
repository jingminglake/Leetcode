class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {
        int m = board.length, n = board[0].length;
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        int[][] dirs = {{-1, -1}, {-1, 0}, {-1, 1},
                        {0, -1}, {0, 1},
                        {1, -1}, {1, 0}, {1, 1}};
        if (board[click[0]][click[1]] == 'E') {
            Queue<int[]> q = new LinkedList<>();
            board[click[0]][click[1]] = 'B'; // Add flag before put something into queue to avoid dups
            q.offer(click);
            while (!q.isEmpty()) {
                int[] p = q.poll();
                int adjMineNum = getAdjMineNum(board, p[0], p[1], dirs, m, n);
                if (adjMineNum == 0) {
                    for (int[] dir : dirs) {
                        int neighbor_i = p[0] + dir[0];
                        int neighbor_j = p[1] + dir[1];
                        if (neighbor_i < 0 || neighbor_i >= m || neighbor_j < 0 || neighbor_j >= n)
                            continue;
                        if (board[neighbor_i][neighbor_j] != 'E') continue;
                        board[neighbor_i][neighbor_j] = 'B'; // Add flag before put something into queue to avoid dups
                        q.offer(new int[]{neighbor_i, neighbor_j});
                    }
                } else {
                    board[p[0]][p[1]] = (char)('0' + adjMineNum); 
                }
            }
        }
        return board;
    }
    
    private int getAdjMineNum(char[][] board, int i, int j, int[][] dirs, int m, int n) {
        int num = 0;
        for (int[] dir : dirs) {
            int neighbor_i = i + dir[0];
            int neighbor_j = j + dir[1];
            if (neighbor_i < 0 || neighbor_i >= m || neighbor_j < 0 || neighbor_j >= n)
                continue;
            if (board[neighbor_i][neighbor_j] == 'M') num++;
        }
        return num;
    }
}
