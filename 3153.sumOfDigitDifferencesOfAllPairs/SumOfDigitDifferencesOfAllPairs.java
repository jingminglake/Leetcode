class Solution {
    public long sumDigitDifferences(int[] nums) {
        long res = 0;
        int numberLen = String.valueOf(nums[0]).length();
        int[] nums_in_flight = new int[nums.length];
        for (int i = 0; i < nums.length; i++) nums_in_flight[i] = nums[i];

        for (int i = 0; i < numberLen; i++) {
            int[] digits = new int[nums_in_flight.length];
            for (int j = 0; j < nums_in_flight.length; j++) {
                digits[j] = nums_in_flight[j] % 10;
                nums_in_flight[j] /= 10;
            }
            res += helper(digits);
        }
        return res;
    }

    private long helper(int[] digits) {
        long res = 0;
        int[] tenth = new int[10];
        for (int i = 0; i < digits.length; i++) {
            tenth[digits[i]]++;
        }

        for (int i = 0; i <= 9; i++) {
            if (tenth[i] == 0) continue;
            for (int j = i + 1; j <= 9; j++) {
                if (tenth[j] == 0) continue;
                res += tenth[i] * tenth[j];
            }

        }
        return res;
    }
}