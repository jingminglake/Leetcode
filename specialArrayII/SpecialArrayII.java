class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        boolean[] result = new boolean[queries.length];
        Map<Integer, Integer> dp = new HashMap<Integer, Integer>();
        for (int i = 0; i < queries.length; i++) {
            result[i] = isArraySpecialHelper(nums, dp, queries[i][0], queries[i][1]);
        }
        return result;
    }

    private boolean isArraySpecialHelper(int[] nums, Map<Integer, Integer> dp, int start, int end) {
        if (start == end) return true;
        if (dp.containsKey(start) && dp.get(start) >= end) {
            return true;
        }
        for (int i = start; i < end; i++) {
            if ( (nums[i] + nums[i + 1]) % 2 == 0) {
                return false;
            }
        }

        dp.put(start, end);
        return true;
    }
}