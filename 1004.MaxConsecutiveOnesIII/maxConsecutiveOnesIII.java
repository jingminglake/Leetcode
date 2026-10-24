class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int left = 0, right = 0;
        int zeros = 0;
        int res = 0;
        while (right < n) {
            if (nums[right] == 0) zeros++;

            // make the window valid
            while (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            res = Math.max(res, right - left + 1);
            right++;
        }
        return res;
    }
}

// [0, 0] k = 0
// 1. right = 0, zero = 1, left = 1, res = 0
// 2. right = 1, zero = 1, left = 2, res = 0

// [1, 1, 1], k = 2
// 1. right = 0, zero = 0, left = 0, res = 1
// 2. right = 1; zero = 0, left = 0, res = 2
// 3. right = 2, zero = 0, left = 0, res = 3