class Solution {
    public int maximumLength(int[] nums) {
        if (nums.length == 2) return 2;
        int res = 0;
        int countOdd = 0, countEven = 0;
        int countOddEvenAlt = 0; // odd even appear alternately

        int nextP = nums[0] % 2; // next parity
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 != 0) {
                countOdd++;
            } else {
                countEven++;
            }

            if (nums[i] % 2 == nextP) {
                countOddEvenAlt++;
                nextP = 1 - nextP; // 1 -> 0, 0 -> 1
            }
        }
        res = Math.max(res, countOdd);
        res = Math.max(res, countEven);
        res = Math.max(res, countOddEvenAlt);
        return res;
    }

}