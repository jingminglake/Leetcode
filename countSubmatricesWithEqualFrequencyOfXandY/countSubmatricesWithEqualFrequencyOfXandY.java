class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dpX = new int[m][n];
        int[][] dpY = new int[m][n];
        int res = 0;
        if (grid[0][0] == 'X') dpX[0][0] = 1;
        else if (grid[0][0] == 'Y') dpY[0][0] = 1;

        for (int j = 1; j < n; j++) {
            dpX[0][j] = dpX[0][j - 1];
            dpY[0][j] = dpY[0][j - 1];
            if (grid[0][j] == 'X') {
                dpX[0][j]++;
            } else if (grid[0][j] == 'Y') {
                dpY[0][j]++;
            }

            if (dpX[0][j] > 0 && dpX[0][j] == dpY[0][j]) res++;
        }
        for (int i = 1; i < m; i++) {
            dpY[i][0] = dpY[i - 1][0];
            dpX[i][0] = dpX[i - 1][0];
            if (grid[i][0] == 'X') {
                dpX[i][0]++;
            } else if (grid[i][0] == 'Y') {
                dpY[i][0]++;
            }

            if (dpX[i][0] > 0 && dpX[i][0] == dpY[i][0]) res++;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dpX[i][j] = dpX[i - 1][j] + dpX[i][j - 1] - dpX[i - 1][j - 1];
                dpY[i][j] = dpY[i - 1][j] + dpY[i][j - 1] - dpY[i - 1][j - 1];
                if (grid[i][j] == 'X') {
                    dpX[i][j]++;
                } else if (grid[i][j] == 'Y') {
                    dpY[i][j]++;
                }

                if (dpX[i][j] > 0 && dpX[i][j] == dpY[i][j]) res++;
            }
        }
        return res;
    }
}