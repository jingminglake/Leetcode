class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> res = new ArrayList<>();
        int i = 0;

        // add left no overlapping intervals, can be 0
        while (i < intervals.length && intervals[i][1] < newInterval[0]) {
            res.add(intervals[i++]);
        }

        // find all overlapping and merge into one, at least one
        int start = newInterval[0];
        int end = newInterval[1];
        while (i < intervals.length && intervals[i][0] <= newInterval[1]) {
            start = Math.min(start, intervals[i][0]);
            end = Math.max(end, intervals[i][1]);
            i++;
        }
        res.add(new int[] {start, end});

        // add right no overlapping
        while (i < intervals.length) {
            res.add(intervals[i++]);
        }
        return res.toArray(new int[res.size()][]);
    }
}
