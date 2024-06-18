class Solution {
    public int countCompleteDayPairs(int[] hours) {
        int res = 0;
        for (int i = 0; i < hours.length; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (((hours[i] % 24 + hours[j] % 24) % 24) == 0) res++;
            }
        }
        return res;
    }
}