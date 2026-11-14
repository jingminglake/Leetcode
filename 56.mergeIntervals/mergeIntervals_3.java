class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> res = new ArrayList<>();

        int curIndex = 1;
        res.add(new int[]{intervals[0][0], intervals[0][1]});
        while (curIndex < intervals.length) {
            // last interval in res = the merged interval still open to extension (all earlier ones are final)
            int[] lastInterval = res.get(res.size() - 1);
            if (intervals[curIndex][0] <= lastInterval[1]) { // [1, 3] [3, 4] -> [1, 4]
                // merge
                lastInterval[1] = Math.max(lastInterval[1], intervals[curIndex][1]);
            } else {
                // add
                res.add(new int[]{intervals[curIndex][0], intervals[curIndex][1]});
            }
            curIndex++;
        }
        int[][] arr = new int[res.size()][2];
        for (int i = 0; i < res.size(); i++) {
            arr[i] = res.get(i);
        }
        return arr;
    }
}

/*

1. [1, 3]  [2, 6] -> [1, 6]
2. [1, 3]  [1, 2] -> [1, 3]
3. [1, 3]  [4, 5] -> [1, 3], [4, 5]
4. [1, 3]  [3, 4] -> [1, 4]

ex [1, 3] [1, 2]
res.add([1, 3])
lastInterval = [1, 3]

curIndex = 1
intervals[curIndex][0] = 1 <= lastIntervals[1]=3 true -> lastInterval[1] = max{3, intervals[curIndex[1] = 2]} = 3
res = {[1, 3]}
curIndex = 2 < 2 ? false 
arr = [
[1, 3]
]

return arr
*/