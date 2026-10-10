class Solution {
    public boolean hasValidPath(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] dirs = {
            {}, // 0
            {{0, -1}, {0, 1}}, // 1
            {{-1, 0}, {1, 0}}, // 2
            {{0, -1}, {1, 0}}, // 3
            {{0, 1}, {1, 0}}, // 4
            {{0, -1}, {-1, 0}}, // 5
            {{0, 1}, {-1, 0}} // 6
        };

        boolean[][] visited = new boolean[m][n];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        visited[0][0] = true;

        while (!queue.isEmpty()) {
            int[] peek = queue.poll();
            int i = peek[0], j = peek[1];
            if (i == m - 1 && j == n - 1) return true;

            for (int[] dir : dirs[grid[i][j]]) {
                int nextI = dir[0] + i;
                int nextJ = dir[1] + j;
                if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n || visited[nextI][nextJ]) continue;
                for (int[] backDir : dirs[grid[nextI][nextJ]]) {
                    int backI = nextI + backDir[0];
                    int backJ = nextJ + backDir[1];
                    if (backI == i && backJ == j) {
                        visited[nextI][nextJ] = true;
                        queue.offer(new int[]{nextI, nextJ});
                        break;
                    }
                }
            }
        }
        return false;
    }
}