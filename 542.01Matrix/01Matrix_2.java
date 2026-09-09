class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] res = new int[m][n];
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) q.add(new int[]{i, j});
            }
        }
        int level = 0;
        while (!q.isEmpty()) {
            int qSize = q.size(); // level size
            int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for (int i = 0; i < qSize; i++) {
                int[] p = q.poll();
                for (int[] dir : dirs) {
                    int nextI = p[0] + dir[0];
                    int nextJ = p[1] + dir[1];
                    if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n) continue;
                    if (mat[nextI][nextJ] == 0) continue;
                    if (mat[nextI][nextJ] == 1) {
                        res[nextI][nextJ] = level + 1;
                        mat[nextI][nextJ] = 0;
                        q.add(new int[] {nextI, nextJ});
                    }
                }
            }
            level++;
        }
        return res;
    }
}