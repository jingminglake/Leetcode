class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rowSum = vector<int>(n, 0);
        colSum = vector<int>(n, 0);
        diagonal = 0;
        antiDiagonal = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int toAdd = player == 1 ? 1 : -1;
        rowSum[row] += toAdd;
        colSum[col] += toAdd;
        if (row == col) {
            diagonal += toAdd;
        }
        if (col == (colSum.size() - row - 1)) {
            antiDiagonal += toAdd;
        }
        int size = rowSum.size();
        if (abs(rowSum[row]) == size || abs(colSum[col]) == size 
            || abs(diagonal) == size || abs(antiDiagonal) == size)
            return player;
        else
            return 0;
    }
    vector<int> rowSum;
    vector<int> colSum;
    int diagonal;
    int antiDiagonal;
    char mark[2];
};
