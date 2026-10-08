class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        // build graph
        List<List<int[]>> graph = new ArrayList<>(); // 1 -> [{2, d1}, {3, d2}]; 2 -> [{1, d1}]
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] time : times) {
            graph.get(time[0]).add(new int[]{time[1], time[2]});
        }
        // dist init
        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[k] = 0;

        // pq
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        pq.offer(new int[]{0, k}); // {distance, node}

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int d = top[0];
            int node = top[1];
            if (d > dist[node]) continue;
            for (int[] neighbor : graph.get(node)) {
                int nNode = neighbor[0];
                int nD = neighbor[1];
                if (nD + d < dist[nNode]) { // can update
                   dist[nNode] = nD + d;
                   pq.offer(new int[]{dist[nNode], nNode});
                }
            }
        }

        // check dist
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == Integer.MAX_VALUE) return -1;
            res = Math.max(res, dist[i]);
        }
        return res;
    }
}