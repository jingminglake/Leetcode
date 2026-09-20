class Solution {
    public long maximumCoins(int[][] coins, int k) {
        Arrays.sort(coins, (a, b) -> Integer.compare(a[0], b[0]));

        int rangeSize = coins.length;
        // preSum for each start point
        long[] preSumL = new long[rangeSize + 1];
        preSumL[0] = 0;
        for (int i = 1; i <= rangeSize; i++) {
            preSumL[i] = preSumL[i - 1] + ((long)coins[i - 1][1] - coins[i - 1][0] + 1) * coins[i - 1][2];
        }

        long res = 0;
        for (int[] range : coins) {
            long l = range[0];
            long r = range[1];
            
            // 1. [l, l + k - 1]
            res = Math.max(res, rangeSum(l, l + k - 1, preSumL, coins));

            // 2. [r - k + 1, r]
            res = Math.max(res, rangeSum(r - k + 1, r, preSumL, coins));
        }
        return res;
    }

    private long rangeSum(long left, long right, long[] preSumL, int[][] coins) {
        return preSum(right, preSumL, coins) - preSum(left - 1, preSumL, coins); 
    }

    private long preSum(long x, long[] preSumL, int[][] coins) {
        if (x < 0) return 0;
        // find last range index

        int left = 0; 
        int right = coins.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (coins[mid][0] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int lastIndex = left - 1;
        if (lastIndex == -1) return 0;
        long lastRangeLeft = coins[lastIndex][0];
        long lastRangeRight = coins[lastIndex][1];
        int lastRangeCoin = coins[lastIndex][2];
        long res = preSumL[lastIndex];
        if (x >= lastRangeLeft && x <= lastRangeRight) {
            res += (x - lastRangeLeft + 1) * lastRangeCoin;
        } else {
            res += (lastRangeRight - lastRangeLeft + 1) * lastRangeCoin;
        }
        return res;
    }
}