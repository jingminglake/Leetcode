class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {
        int m = board.length;
        int n = board[0].length;
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        } else if (board[click[0]][click[1]] >= '1' && board[click[0]][click[1]] <= '8') {
            return board;
        }
        
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> q = new LinkedList<>();
        q.offer(click);
        visited[click[0]][click[1]] = true;
        int[][] dirs = {{-1, -1}, {-1, 0}, {-1, 1}, 
                      {0, -1},           {0, 1},
                      {1, -1},  {1, 0},  {1, 1}};
        while (!q.isEmpty()) {
            int[] peek = q.poll();

            int mineNum = 0;
            for (int[] dir : dirs) {
                int nextI = peek[0] + dir[0];
                int nextJ = peek[1] + dir[1];
                if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n) continue;
                if (board[nextI][nextJ] == 'M') mineNum++;
            }
            if (mineNum > 0) {
                board[peek[0]][peek[1]] = (char)('0' + mineNum);
            } else {
                board[peek[0]][peek[1]] = 'B';
                for (int[] dir : dirs) {
                    int nextI = peek[0] + dir[0];
                    int nextJ = peek[1] + dir[1];
                    if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n || visited[nextI][nextJ]) continue;
                    if (board[nextI][nextJ] == 'E') {
                        visited[nextI][nextJ] = true;
                        q.offer(new int[]{nextI, nextJ});
                    }
                 }
            }
        }
        return board;
    }
}