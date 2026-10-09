class Solution {
    public int[] restoreArray(int[][] adjacentPairs) {
        Map<Integer, List<Integer>> m = new HashMap<>();
        for (int[] pair : adjacentPairs) {
            m.computeIfAbsent(pair[0], x -> new ArrayList<>()).add(pair[1]);
            m.computeIfAbsent(pair[1], x -> new ArrayList<>()).add(pair[0]);
        }

        int[] res = new int[m.size()];
        for (Map.Entry<Integer, List<Integer>> entry : m.entrySet()) {
            if (entry.getValue().size() == 1) {
                res[0] = entry.getKey();
                res[1] = entry.getValue().get(0);
                break;
            }
        }

        for (int i = 2; i < res.length; i++) {
            List<Integer> neighbors = m.get(res[i - 1]);
            for (int n : neighbors) {
                if (n == res[i - 2]) continue;
                res[i] = n;
            }
        }
        return res;
    }
}