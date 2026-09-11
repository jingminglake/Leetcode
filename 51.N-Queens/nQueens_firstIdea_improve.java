class Solution {
    static class Node {
        public Node(int row, int col) {
            x = row;
            y = col;
        }
        int x;
        int y;
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<List<String>>();
        char[][] board = new char[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }
        List<Node> path = new ArrayList<>();
        dfs(board, n, res, path, 0);
        return res;
    }
    
    private void dfs(char[][] board, int n, List<List<String>> res, List<Node> path, int row) {
        if (row == n) {
            res.add(construct(board));
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(path, row, col)) {
                board[row][col] = 'Q';
                path.add(new Node(row, col));
                dfs(board, n, res, path, row + 1);
                board[row][col] = '.';
                path.remove(path.size() - 1);
            }
        }
    }

    private boolean isValid(List<Node> path, int row, int col) {
        boolean res = true;
        if (path != null) {
            for (Node n : path) {
                if (n.x == row || n.y == col || n.x + n.y == row + col || n.x + col == row + n.y) {
                    res = false;
                    break;
                }
            }
        }
        return res;
    }
    
    private List<String> construct(char[][] board) {
        List<String> res = new LinkedList<String>();
        for(int i = 0; i < board.length; i++) {
            String s = new String(board[i]);
            res.add(s);
        }
        return res;
    }
}
