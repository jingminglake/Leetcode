class Solution {
    public int minimumArea(int[][] grid) {
        int topI = grid.length;
        int downI = 0;
        int leftJ = grid[0].length;
        int rightJ = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    topI = Math.min(topI, i);
                    downI = Math.max(downI, i);
                    leftJ = Math.min(leftJ, j);
                    rightJ = Math.max(rightJ, j);
                }
            }
        }
        return (rightJ - leftJ + 1) * (downI - topI + 1);
    }
}