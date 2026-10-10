class Solution {
    public int waysToSplit(int[] nums) {
        final long MOD = 1_000_000_007;
        int n = nums.length;

        long[] preSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        long res = 0;
        int jStart = 2;
        int jEnd = 2;
        for (int i = 1; i <= n - 2; i++) {
            // jStart and jEnd 永远不会变小
            jStart = Math.max(jStart, i + 1);
            while (jStart < n && preSum[jStart] < 2 * preSum[i]) {
                jStart++;
            }

            jEnd = Math.max(jEnd, jStart);
            while (jEnd < n && 2*preSum[jEnd] <= preSum[n] + preSum[i]) {
                jEnd++;
            }

            res = (res + jEnd - jStart) % MOD;
        }
        return (int) res;
    }
}