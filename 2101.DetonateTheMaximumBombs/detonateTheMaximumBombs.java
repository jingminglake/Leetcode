class Solution {
    public int maximumDetonation(int[][] bombs) {
        int res = 0;
        // build graph
        Map<Integer, List<Integer>> graph = new HashMap<>();
        int n = bombs.length;
        for (int i = 0; i < n; i++) {
             graph.put(i, new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                boolean[] d = detonate(bombs, i, j); // {i -> j, j -> i}
                if (d[0]) {
                    // i -> j
                    graph.get(i).add(j);
                }
                if (d[1]) {
                    // j -> i
                    graph.get(j).add(i);
                }
            }
        }

        // visit all nodes and find the max number
        for (int i = 0; i < n; i++) {
            boolean[] visited = new boolean[n];
            int nodeNum = dfs(i, visited, graph);
            res = Math.max(res, nodeNum);
        }
        return res;
    }

    private int dfs(int start, boolean[] visited, Map<Integer, List<Integer>> graph) {
        visited[start] = true;
        int res = 1; // node
        for (int neighbor : graph.get(start)) {
            if (!visited[neighbor]) {
                res += dfs(neighbor, visited, graph);
            }
        }
        return res;
    }

    private boolean[] detonate(int[][] bombs, int i, int j) {
        long ix = bombs[i][0], iy = bombs[i][1], ir = bombs[i][2];
        long jx = bombs[j][0], jy = bombs[j][1], jr = bombs[j][2];
        long dx = ix - jx;
        long dy = iy - jy;
        long dist = dx * dx + dy * dy;
        long iSquare = ir * ir;
        long jSquare = jr * jr;
        return new boolean[]{ iSquare >= dist, jSquare >= dist};
    }

    /*
    ex. bombs = [[2,1,3],[6,1,4]] 
        graph: 0 : []
               1 : [0]
        
        dfs(0) visited[0]? false return res=1

        dfs(1) visited[1]? false res = 1 + dfs(0) = 2
               dfs(0) visited[0]? false return 1
    return 2

    */
}