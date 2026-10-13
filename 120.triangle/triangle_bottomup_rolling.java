class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] prev = new int[n];
        for (int j = 0; j < n; j++) {
            prev[j] = triangle.get(n - 1).get(j);
        }

        
        for (int i = n - 2; i >= 0; i--) {
            int[] cur = new int[n];
            for (int j = 0; j <= i; j++) {
                int down = prev[j];
                int downRight = prev[j + 1];
                cur[j] = Math.min(down, downRight) + triangle.get(i).get(j);
            }
            prev = cur;
        }
        return prev[0];
    }
}