class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) < 2 * desiredTotal) return false;
        
        boolean[] visited = new boolean[maxChoosableInteger + 1];
        memo = new HashMap<>();
        return dfs(maxChoosableInteger, desiredTotal, visited, 0);
    }
    
    private Map<String, Boolean> memo;
    
    private boolean dfs(int maxChoosableInteger, int desiredTotal, boolean[] visited, int path) {
        String key = Arrays.toString(visited);
        if (memo.containsKey(key)) return memo.get(key);
        for (int i = maxChoosableInteger; i >= 1; i--) {
            if (!visited[i]) {
                boolean levelRes = true;
                if (path + i >= desiredTotal) {
                    memo.put(key, true);
                    return true;
                }
                visited[i] = true;
                path += i;
                if (dfs(maxChoosableInteger, desiredTotal, visited, path)) {
                    levelRes = false;
                }
                path -= i;
                visited[i] = false;
                if (levelRes) {
                    memo.put(key, true);
                    return true;
                }
            }
        }
        memo.put(key, false);
        return false;
    }
}
