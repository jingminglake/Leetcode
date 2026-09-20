class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));
        int[] last = intervals[0];
        int cnt = 1;

        for (int i = 1; i < n; i++) {
            int[] cur = intervals[i];
            if (cur[0] >= last[1]) {
                last = cur;
                cnt++;
            }
        }
        return n - cnt;
    }
}