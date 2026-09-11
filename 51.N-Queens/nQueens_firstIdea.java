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
        List<List<Node>> res = new ArrayList<>();
        List<Node> path = new ArrayList<>();
        dfs(n, res, path, 0);
        
        List<List<String>> boardRes = new ArrayList<List<String>>();
        
        for (List<Node> list : res) {
            char[][] boardX = getOneBoard(n);
            for (Node node : list) {
                boardX[node.x][node.y] = 'Q';
            }
            boardRes.add(construct(boardX));
        }
        return boardRes;
    }
    
    private char[][] getOneBoard(int n) {
        char[][] board = new char[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }
        return board;
    }
    
    private List<String> construct(char[][] board) {
        List<String> res = new LinkedList<String>();
        for(int i = 0; i < board.length; i++) {
            String s = new String(board[i]);
            res.add(s);
        }
        return res;
    }
    
    private void dfs(int n, List<List<Node>> res, List<Node> path, int row) {
        if (row == n) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(path, row, col)) {
                path.add(new Node(row, col));
                dfs(n, res, path, row + 1);
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
                }
            }
        }
        return res;
    }
}
