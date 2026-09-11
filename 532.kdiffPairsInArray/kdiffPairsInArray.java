class Solution {
    public int findPairs(int[] nums, int k) {
        int res = 0;
        Map<Integer, Integer> m = new HashMap<>();
        for (int n : nums) {
            if (!m.containsKey(n)) {
                m.put(n, 0);
            }
            m.put(n, m.get(n) + 1);
        }
        for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
            if (k == 0) {
                if (entry.getValue() > 1) res++;
            } else {
                if (m.containsKey(entry.getKey() + k)) res++;
            }
        }
        return res;
    }
}
