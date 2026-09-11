class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        Map<Integer,Integer> m = new HashMap<Integer,Integer>();
        for (int t : target) {
            m.put(t, m.getOrDefault(t, 0) + 1);
        }
        for (int a : arr) {
            int n = m.getOrDefault(a, 0);
            if (n <= 0) return false;
            m.put(a, n - 1);
        }
        for (Integer i : m.values()) {
            if (i != 0) return false;
        }
        return true;
    }
}
