class Solution {
    public int[][] kClosest(int[][] points, int k) {
        List<int[]> res = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            double dis1 = a[0] * a[0] + a[1] * a[1];
            double dis2 = b[0] * b[0] + b[1] * b[1];
            return Double.compare(dis1, dis2);
        });

        // it's log(N), not log(K), so not OK in the interview
        for (int[] p : points) {
            pq.add(p);
        }
        for (int i = 0; i < k; i++) {
            if (pq.isEmpty()) break;
            int[] p = pq.poll();
            res.add(p);
        }
        return res.toArray(new int[res.size()][]);
    }
}