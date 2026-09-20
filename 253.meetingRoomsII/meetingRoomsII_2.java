class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int len = intervals.length;
        int[][] events = new int[2 * len][2];
        for (int i = 0; i < len; i++) {
            events[2 * i] = new int[] {intervals[i][0], 1}; // start + 1
            events[2 * i + 1] = new int[] {intervals[i][1], -1}; // end  -1
        }

        Arrays.sort(events, (a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            } else {
                return Integer.compare(a[1], b[1]); // consider end before start b/c [0, 1] sharing one room with [1, 2]
            }
        });

        int ongoing = 0;
        int res = 0;
        for (int[] e : events) {
            ongoing += e[1];
            res = Math.max(res, ongoing);
        }
        return res;
    }
}