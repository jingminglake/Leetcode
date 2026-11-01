class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        int m = grid.length;
        int n = grid[0].length;

        // each 1 visit only one time
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, visited, i, j);
                    res = Math.max(res, area);
                }
            }
        }
        return res;
    }

    private int dfs(int[][] grid, boolean[][] visited, int i, int j) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) {
            return 0;
        }
        if (grid[i][j] == 0 || visited[i][j]) return 0;

        visited[i][j] = true;
        int area = 1;
        area += dfs(grid, visited, i + 1, j); // down
        area += dfs(grid, visited, i - 1, j); // up
        area += dfs(grid, visited, i, j + 1); // right
        area += dfs(grid, visited, i, j - 1); // left
        return area; 
    }
}

/*

[[0,0,0]] 

i = 0, j = 0 grid[i][j] == 0
i = 0, j = 1 grid[i][j] == 0
i = 0, j = 2 grid[i][j] == 0
res = 0


[[1,1],
 [0,1]]	3

dfs(0,0): 不越界，grid=1，未访问 → visited[0][0], area=1 return 3
  dfs1(1,0): grid[1][0]=0 → return 0
  dfs1(-1,0): -1 < 0 return 0
  dfs1(0,1): grid[0][1] == 1 mark visited[0][1]= true; area=1 return 2
      dfs2(1,1): grid[1][1]=1 mark visited[1][1]=true; area=1 return 1
         dfs3(0,1): visited[0][1]=true return 0
         dfs3(2,1): 2 >= 2? return 0
         dfs3(1,0): grid[1][0]=0  return 0
         dfs3(1,2): 2 >= 2? return 0
      dfs2(-1,1): -1 < 0 return 0
      dfs2(0,0): visited[0][0]=true return 0
      dfs2(0,2): 2 >= 2? return 0
  dfs1(0,-1): -1 < 0 return 0

*/