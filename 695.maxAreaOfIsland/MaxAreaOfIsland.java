import java.util.*;

class MaxAreaOfIsland {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        if (grid == null || grid.length == 0)
            return res;
        int[][] dirs = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    res = Math.max(res, bfs(grid, i, j, dirs, visited));
                }
            }
        }
        return res;
    }
    int bfs(int[][] grid, int i, int j, int[][] dirs, boolean[][] visited) {
        int res = 1;
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{i, j});
        visited[i][j] = true;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int[] dir : dirs) {
                int nextI = cur[0] + dir[0];
                int nextJ = cur[1] + dir[1];
                if (nextI < 0 || nextI >= grid.length || nextJ < 0 || nextJ >= grid[0].length || grid[nextI][nextJ] == 0 || visited[nextI][nextJ])
                    continue;
                visited[nextI][nextJ] = true;
                res++;
                q.offer(new int[]{nextI, nextJ});
            }
        }
        return res;
    }
	public static void main(String[] args) {
		MaxAreaOfIsland s = new MaxAreaOfIsland();
		int[][] grid = new int[][]{{0,0,1,0,0,0,0,1,0,0,0,0,0},
								   {0,0,0,0,0,0,0,1,1,1,0,0,0},
								   {0,1,1,0,1,0,0,0,0,0,0,0,0},
								   {0,1,0,0,1,1,0,0,1,0,1,0,0},
								   {0,1,0,0,1,1,0,0,1,1,1,0,0},
								   {0,0,0,0,0,0,0,0,0,0,1,0,0},
								   {0,0,0,0,0,0,0,1,1,1,0,0,0},
								   {0,0,0,0,0,0,0,1,1,0,0,0,0}};
		System.out.println(s.maxAreaOfIsland(grid));
	}
}
