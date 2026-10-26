class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int left = 0;
        Queue<Integer> zerosQ = new LinkedList<>();
        int res = 0;
        int lastZero = -1;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zerosQ.offer(right);
                if (zerosQ.size() > k)
                    lastZero = zerosQ.poll();
                left = lastZero + 1;
            }

            res = Math.max(res, right - left + 1);
        }
        return res;
    }
}
