class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<>();
        if (n == 1) {
            res.add(0);
            return res;
        }
        Map<Integer, List<Integer>> graph = new HashMap<>();
        int[] indegree = new int[n];
        for (int[] edge : edges) {
            if (!graph.containsKey(edge[0])) {
                graph.put(edge[0], new ArrayList<>());
            }
            graph.get(edge[0]).add(edge[1]);
            if (!graph.containsKey(edge[1])) {
                graph.put(edge[1], new ArrayList<>());
            }
            graph.get(edge[1]).add(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.offer(i);
            }
        }
        
        int remain = n;
        while (!q.isEmpty()) {
            if (remain <= 2) break;
            int q_size = q.size();
            remain -= q_size;
            for (int i = 0; i < q_size; i++) {
                int leave = q.poll();
                for (int neighbor : graph.get(leave)) {
                    if (--indegree[neighbor] == 1) {
                        q.offer(neighbor);
                    }
                }
            }
        }
        
        while (!q.isEmpty()) {
            res.add(q.poll());
        }
        return res;
    }
}
