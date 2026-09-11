class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> res = new ArrayList<>();
        res.add(new int[]{intervals[0][0], intervals[0][1]});
        int i = 1;
        while (i < intervals.length) {
            int[] last = res.get(res.size() - 1);
            if (intervals[i][0] > last[1]) {
                res.add(new int[]{intervals[i][0], intervals[i][1]});
            } else {
                int newEnd = Math.max(last[1], intervals[i][1]);
                last[1] = newEnd;
            }
            i++;
        }
        return res.toArray(new int[res.size()][]);
    }
}