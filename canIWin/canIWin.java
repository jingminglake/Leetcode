class Solution {
    private Map<String, Boolean> memo;
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) < 2 * desiredTotal) return false;
        boolean[] visited = new boolean[maxChoosableInteger + 1];
        memo = new HashMap<>();
        return dfs(maxChoosableInteger, desiredTotal, visited);
    }
    
    public boolean dfs(int maxChoosableInteger, int remain, boolean[] visited) {
        String key = Arrays.toString(visited);
        if (memo.containsKey(key)) return memo.get(key);
        
        for (int i = maxChoosableInteger; i >= 1; i--) {
            if (visited[i]) continue;
            boolean[] op_visited = getOpVisited(visited, i);
            if (remain <= i || !dfs(maxChoosableInteger, remain - i, op_visited)) {
                memo.put(key, true);
                return true;
            }
        }
        memo.put(key, false);
        return false;
    }
    
    private boolean[] getOpVisited(boolean[] visited, int choosed) {
        boolean[] op_visited = new boolean[visited.length];
        for (int i = 0; i < visited.length; i++) {
            op_visited[i] = visited[i];
        }
        op_visited[choosed] = true;
        return op_visited;
    }
}
