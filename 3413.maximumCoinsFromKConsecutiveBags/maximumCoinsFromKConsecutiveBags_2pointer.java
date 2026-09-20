class Solution {
    public long maximumCoins(int[][] coins, int k) {
        Arrays.sort(coins, (a, b) -> Integer.compare(a[0], b[0]));

        long res = 0;
        // 1. [l, l + k - 1]
        res = Math.max(res, rangeSumLeft(coins, k));

        // 2. [r - k + 1, r]
        res = Math.max(res, rangeSumRight(coins, k));
        return res;
    }

    private long rangeSumLeft(int[][] coins, int k) {
        long res = 0;
        int n = coins.length;
        int right = 0; // point to first not full section
        long fullSum = 0;
        
        for (int left = 0; left < n; left++) {
            long windowRight = (long) coins[left][0] + k - 1;

            // find how many section get fully covered
            while (right < n && coins[right][1] <= windowRight) {
                fullSum += ((long) coins[right][1] - coins[right][0] + 1) * coins[right][2];
                right++;
            }

            // the section right point to now may has partial result
            long partial = 0;
            if (right < n && coins[right][0] <= windowRight) {
                long overlapLength = windowRight - coins[right][0] + 1;
                partial = overlapLength * coins[right][2];
            }
            
            // update res
            res = Math.max(res, fullSum + partial);

            // try remove left, prepare for next left + 1 round
            if (right > left) {
                // coins[left] was added to fullSum
                fullSum -= ((long) coins[left][1] - coins[left][0] + 1) * coins[left][2];
            } else {
                // left section > window size
                fullSum = 0;
                right = left + 1; // left, right start from same index next round
            }
        }
        return res;
    }

    private long rangeSumRight(int[][] coins, int k) {
        long res = 0;
        int n = coins.length;
        int left = 0; // point to first not full section
        long fullSum = 0;
        
        for (int right = 0; right < n; right++) {
            long windowLeft = (long) coins[right][1] - k + 1;

            // add full right first, may -partial later 
            fullSum += ((long) coins[right][1] - coins[right][0] + 1) * coins[right][2];

            // remove all the sections outside windowLeft
            while (left <= right && coins[left][1] < windowLeft) {
                fullSum -= ((long) coins[left][1] - coins[left][0] + 1) * coins[left][2];
                left++;
            }

            // the section which left point to now may has partial result
            long partial = 0;
            if (left <= right && coins[left][0] < windowLeft) {
                long overlapLength = windowLeft - coins[left][0];
                partial = overlapLength * coins[left][2];
            }
            
            // update res
            res = Math.max(res, fullSum - partial);
        }
        return res;
    }
}