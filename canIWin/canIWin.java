class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) < 2 * desiredTotal) return false;
        
        boolean[] visited = new boolean[maxChoosableInteger + 1];
        memo = new HashMap<>();
        return dfs(maxChoosableInteger, desiredTotal, visited);
    }
    
    private Map<String, Boolean> memo;
    
    private boolean dfs(int maxChoosableInteger, int desiredTotal, boolean[] visited) {
        String key = Arrays.toString(visited);
        if (memo.containsKey(key)) return memo.get(key);
        
        for (int i = maxChoosableInteger; i >= 1; i--) {
            if (!visited[i]) {
                visited[i] = true;
                if (desiredTotal <= i || !dfs(maxChoosableInteger, desiredTotal - i, visited)) {
                    visited[i] = false;
                    memo.put(key, true);
                    return true;
                }
                visited[i] = false;
            }
        }
        memo.put(key, false);
        return false;
    }
}
