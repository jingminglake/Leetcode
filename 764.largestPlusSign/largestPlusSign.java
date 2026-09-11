class Solution {
    public int orderOfLargestPlusSign(int n, int[][] mines) {
        int res = 0;
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 1;
            }
        }
        for (int[] mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        int[][] left = new int[n][n];
        int[][] right = new int[n][n];
        int[][] up = new int[n][n];
        int[][] down = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    right[i][j] = 0;
                    down[i][j] = 0;
                } else {
                    if (j - 1 < 0) right[i][j] = 1;
                    else right[i][j] = right[i][j - 1] + 1;
                    if (i - 1 < 0) down[i][j] = 1;
                    else down[i][j] = down[i - 1][j] + 1;
                }
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    left[i][j] = 0;
                    up[i][j] = 0;
                } else {
                    if (j + 1 >= n) left[i][j] = 1;
                    else left[i][j] = left[i][j + 1] + 1;
                    if (i + 1 >= n) up[i][j] = 1;
                    else up[i][j] = up[i + 1][j] + 1;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int c = Math.min(Math.min(up[i][j], down[i][j]), Math.min(left[i][j], right[i][j]));
                    res = Math.max(res, c);
                }
            }
        }
        return res;
    }
}
