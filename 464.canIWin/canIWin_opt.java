class Solution {
    private Map<Integer, Boolean> memo;
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) < 2 * desiredTotal) return false;
        int visited = 0;
        memo = new HashMap<>();
        return dfs(maxChoosableInteger, desiredTotal, visited);
    }
    
    public boolean dfs(int maxChoosableInteger, int remain, int visited) {
        if (memo.containsKey(visited)) return memo.get(visited);
        
        for (int i = maxChoosableInteger; i >= 1; i--) {
            if ( (visited & (1 << i)) != 0) continue;
            int op_visited = visited | (1 << i);
            if (remain <= i || !dfs(maxChoosableInteger, remain - i, op_visited)) {
                memo.put(visited, true);
                return true;
            }
        }
        memo.put(visited, false);
        return false;
    }
}
