class Solution {
    public int numIdenticalPairs(int[] nums) {
        int res = 0;
        Map<Integer, Integer> m = new HashMap<Integer, Integer>();
        for (int n : nums) {
            m.put(n, m.getOrDefault(n, 0) + 1);
        }
        for (Integer i : m.values()) {
            if (i > 1) res += i * (i - 1) / 2;
        }
        return res;
    }
}
