class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        Arrays.sort(jobs, (a, b) -> Integer.compare(a[1], b[1]));

        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int curJobIndex = i - 1;
            int floorJobIndex = findLastCompatibleJobIndex(jobs, curJobIndex);
            dp[i] = Math.max(dp[i - 1], dp[floorJobIndex] + jobs[curJobIndex][2]);
        }
        return dp[n];
    }

    private int findLastCompatibleJobIndex(int[][] jobs, int curIndex) {
        int curStart = jobs[curIndex][0];

        int left = 0;
        int right = curIndex;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (jobs[mid][1] > curStart) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
}