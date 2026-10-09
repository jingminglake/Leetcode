class Solution {
    public int countPairs(int[] deliciousness) {
        final int MOD = 1_000_000_007;
        final int MAX_SUM = 1 << 21;
        long res = 0;

        Map<Integer, Integer> m = new HashMap<>();
        for (int d : deliciousness) {
            for (int sum = 1; sum <= MAX_SUM; sum <<= 1) { // 2^0, 2^1, ..., 2^21
               int compelete = sum - d;
               res += m.getOrDefault(compelete, 0);
            }
            m.put(d, m.getOrDefault(d, 0) + 1);
        }

        return (int) (res % MOD);
    }
}