class Solution {
    public int waysToSplit(int[] nums) {
        final long MOD = 1_000_000_007;
        int n = nums.length;

        long[] preSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        long res = 0;
        for (int i = 1; i <= n - 2; i++) {
            // left = preSum[i]; mid = preSum[j] - preSum[i]; right = preSum[n] - preSum[j];
            // => preSum[j] >= 2 * preSum[i] && 2 * preSum[j] <= preSum[n] + preSum[i]
            int jStart = lowerBound(preSum, i + 1, n, 2 * preSum[i]);
            int jEnd = upperBound(preSum, i + 1, n, (preSum[n] + preSum[i]) / 2);

            res = (res + Math.max(0, jEnd - jStart)) % MOD;
        }
        return (int) res;
    }

    // find first x, x >= target
    private int lowerBound(long[] preSum, int left, int right, long target) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (preSum[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    // find first x, x > target
    private int upperBound(long[] preSum, int left, int right, long target) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (preSum[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}