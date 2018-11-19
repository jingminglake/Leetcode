/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    class InteveralCompare implements Comparator<Interval> {
        public int compare(Interval a, Interval b) {
            return a.start - b.start;
        }
    }
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> res = new ArrayList<>();
        if (intervals == null || intervals.size() == 0)
            return res;
        Collections.sort(intervals, new InteveralCompare());
        for (Interval i : intervals) {
            if (res.size() == 0 || res.get(res.size() - 1).end < i.start) {
                res.add(i);
            } else if (res.get(res.size() - 1).end < i.end) {
                Interval it = new Interval(res.get(res.size() - 1).start, i.end);
                res.set(res.size() - 1, it);
            }
        }
        return res;
    }
}
