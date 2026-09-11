class Solution {
    public int[] findRightInterval(int[][] intervals) {
        int m = intervals.length;
        if (m == 1) return new int[]{ -1 };
        int[][] start = new int[m][2];
        for (int i = 0; i < m; i++) {
            start[i][0] = intervals[i][0];
            start[i][1] = i;
        }
        Arrays.sort(start, (a, b) -> a[0] - b[0]);
        
        int[] res = new int[m];
        for (int i = 0; i < m; i++) {
            res[i] = findFirstGreater(start, intervals[i][1]);
        }
        return res;
    }
    
    public int findFirstGreater(int[][] start, int endJ) {
        int left = 0, right = start.length - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (start[mid][0] >= endJ) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (start[left][0] >= endJ) return start[left][1];
        else if (start[right][0] >= endJ) return start[right][1];
        else return -1;
    }
}
