class Solution {

    public Solution(int[] w) {
        random = new Random();
        preSum = new int[w.length];
        preSum[0] = w[0];
        for (int i = 1; i < w.length; i++) {
            preSum[i] = preSum[i - 1] + w[i];
        }
    }
    
    public int pickIndex() {
        int len = preSum.length;
        if (len == 1) return 0;
        int n = random.nextInt(preSum[len - 1]) + 1;
        int left = 0, right = len - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (preSum[mid] >= n) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (preSum[left] >= n) return left;
        else if (preSum[right] >= n) return right;
        else return -1;
    }
    
    private int[] preSum;
    Random random;
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
