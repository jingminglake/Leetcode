class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        boolean[][] visited = new boolean[m][n];

        List<Integer> res = new ArrayList<>();
        visited[0][0] = true;
        dfs(matrix, dirs, 0, visited, res, 0, 0);
        return res;
    }

// 时间：\(O(mn)\)
// visited：\(O(mn)\)
// 递归调用栈：\(O(mn)\)
// 总额外空间：\(O(mn)\)
    private void dfs(int[][] matrix, int[][] dirs, int dIndex, boolean[][] visited, List<Integer> res, int i, int j) {
        res.add(matrix[i][j]);
        int nextI = i + dirs[dIndex][0];
        int nextJ = j + dirs[dIndex][1];
        if (nextI < 0 || nextI >= matrix.length || nextJ < 0 || nextJ >= matrix[0].length || visited[nextI][nextJ]) {
            dIndex = (dIndex + 1) % 4;
            nextI = i + dirs[dIndex][0];
            nextJ = j + dirs[dIndex][1];
            if (nextI < 0 || nextI >= matrix.length || nextJ < 0 || nextJ >= matrix[0].length || visited[nextI][nextJ])
                return;
        }
        visited[nextI][nextJ] = true;
        dfs(matrix, dirs, dIndex, visited, res, nextI, nextJ);
    }
}