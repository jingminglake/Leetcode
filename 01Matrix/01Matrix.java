class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[][] updatedMatrix = new int[m][n];
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    updatedMatrix[i][j] = Integer.MAX_VALUE;
                } else {
                    updatedMatrix[i][j] = 0;
                    q.offer(new int[]{i, j});
                }
            }
        }
        int dist = 0;
        int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            int q_size = q.size();
            dist++;
            for (int k = 0; k < q_size; k++) {
                int[] p = q.poll();
                for (int[] dir : dirs) {
                    int next_i = p[0] + dir[0];
                    int next_j = p[1] + dir[1];
                    if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) continue;
                    if (dist >= updatedMatrix[next_i][next_j]) continue;
                    updatedMatrix[next_i][next_j] = dist;
                    q.offer(new int[]{next_i, next_j});
                }
            }
        }
        return updatedMatrix;
    }
}
