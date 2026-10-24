class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int res = 0;
        int cnt = 0;
        for (int n : nums) {
            if (n == 0) {
                cnt = 0; 
            } else {
                cnt++;
            }
            res = Math.max(res, cnt);
        }
        return res;
    }
}