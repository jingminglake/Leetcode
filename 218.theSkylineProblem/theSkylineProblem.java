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
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        pq.offer(0);
        int prev = 0;
        for (List<Integer> h : height) {
            if (h.get(1) >= 0) {
                pq.offer(h.get(1));
            } else {
                pq.remove(-h.get(1));
            }
            int cur = pq.peek();
            if (cur != prev) {
                res.add(new ArrayList<>(Arrays.asList(h.get(0), cur)));
                prev = cur;
            }
        }
        return res;
    }
}
