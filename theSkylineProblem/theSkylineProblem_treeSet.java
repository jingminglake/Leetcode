class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<List<Integer>> res = new ArrayList<>();
        List<List<Integer>> height = new ArrayList<>();
        for (int[] b : buildings) {
            height.add(new ArrayList<Integer>(Arrays.asList(b[0], b[2])));
            height.add(new ArrayList<Integer>(Arrays.asList(b[1], -b[2])));
        }
        Collections.sort(height, (a, b) -> {
            if (!a.get(0).equals(b.get(0))) return a.get(0) - b.get(0);
            else return b.get(1) - a.get(1);
        });
        TreeMap<Integer, Integer> treeMap = new TreeMap<>(Collections.reverseOrder());
        treeMap.put(0, 1);
        int prev = 0;
        for (List<Integer> h : height) {
            if (h.get(1) >= 0) {
                treeMap.put(h.get(1), treeMap.getOrDefault(h.get(1), 0) + 1);
            } else {
                int count = treeMap.get(-h.get(1));
                if (count == 1) {
                    treeMap.remove(-h.get(1));
                } else {
                    treeMap.put(-h.get(1), count - 1);
                } 
            }
            int cur = treeMap.firstKey();
            if (cur != prev) {
                res.add(new ArrayList<>(Arrays.asList(h.get(0), cur)));
                prev = cur;
            }
        }
        return res;
    }
}
