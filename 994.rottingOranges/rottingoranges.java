class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int numOne = 0;
        int numTwo = 0;
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    numOne++;
                } else if (grid[i][j] == 2) {
                    numTwo++;
                    q.add(new int[]{i, j});
                }
            }
        }
        if (numOne == 0) {
            return 0;
        }
        if (numTwo == 0) {
            return -1;
        }
        // bfs
        int[][] dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        while (!q.isEmpty()) {
            int levelSize = q.size();
            res++;
            for (int i = 0; i < levelSize; i++) {
                int[] point = q.poll();
                for (int[] dir : dirs) {
                    int nextI = point[0] + dir[0];
                    int nextJ = point[1] + dir[1];
                    if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n) continue;
                    if (grid[nextI][nextJ] != 1) continue;
                    grid[nextI][nextJ] = 2;
                    numOne--;
                    q.offer(new int[]{nextI, nextJ});
                }
            }
        }
        if (numOne == 0) return res - 1;
        else return -1;
    }
}

/*
ex1: [[0]]
m = 1, n = 1
num1 = 0 return 0

ex2: [[0, 1]]
m = 1, n = 2
num1 = 1, num2 = 0 return -1

ex3: [[2, 1, 1], 
      [1, 1, 0], 
      [0, 1, 1]]
m = 3, n = 3
num1 = 6, num2 = 1
q: [{0, 0}]

res = 1
point: {0, 0}
next1: {-1, 0} -1 < 0 continue
next2: {1, 0} grid[1][0] = 1 -> grid[1][0] = 2, q.offer {1, 0}
next3: {0, 1} grid[0][1] = 1 -> grid[0][1] = 2, q.offer {0, 1}

point :{1, 0} ->
point : {0, 1} -> 


[[2, 1, 1], 
[1, 1, 0],    levelSize:1 -> res: 1
[0, 1, 1]]

[[2, 2, 1], 
[2, 1, 0],    levelSize:2 -> res: 2
[0, 1, 1]]

[[2, 2, 2], 
[ 2, 2, 0],    levelSize:2 -> res: 3
[ 0, 1, 1]]

[[2, 2, 2], 
[ 2, 2, 0],    levelSize:1 -> res: 4
[ 0, 2, 1]]

[[2, 2, 2], 
[ 2, 2, 0],    levelSize:1 -> res: 5
[ 0, 2, 2]]

[[2,1,0,1]]
m = 1, n = 4
numOne = 2, q: {0, 0}
levelSize = 1, res = 1, rot {0, 1}, numOne=2-1=1
levelSize = 1, res = 2, 
!q.isEmpty() -> 
numOne == 0 false return -1

*/