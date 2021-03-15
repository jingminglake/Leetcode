class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>> res = new ArrayList<>();
        if (matrix == null || matrix.length == 0) return res;
        int m = matrix.length, n = matrix[0].length;
        boolean[][] pacific_can_flow = new boolean[m][n];
        boolean[][] atlantic_can_flow = new boolean[m][n];
        Queue<int[]> pQueue = new LinkedList<>();
        Queue<int[]> aQueue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            pacific_can_flow[i][0] = true;
            atlantic_can_flow[i][n - 1] = true;
            pQueue.offer(new int[] {i, 0});
            aQueue.offer(new int[] {i, n - 1});
        }
        
        for (int j = 0; j < n; j++) {
            pacific_can_flow[0][j] = true;
            atlantic_can_flow[m - 1][j] = true;
            pQueue.offer(new int[] {0, j});
            aQueue.offer(new int[] {m - 1, j});
        }
        bfs(pQueue, pacific_can_flow, matrix, m, n);
        bfs(aQueue, atlantic_can_flow, matrix, m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific_can_flow[i][j] && atlantic_can_flow[i][j]) res.add(new ArrayList<>(Arrays.asList(i, j)));
            }
        }
        return res;
    }
    
    public void bfs(Queue<int[]> q, boolean[][] can_flow, int[][] matrix, int m, int n) {
        int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int[] dir : dirs) {
                int next_i = dir[0] + cur[0];
                int next_j = dir[1] + cur[1];
                if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) continue;
                if (can_flow[next_i][next_j] || matrix[next_i][next_j] < matrix[cur[0]][cur[1]]) continue;
                can_flow[next_i][next_j] = true;
                q.offer(new int[] {next_i, next_j});
            }
        }
    }
}
