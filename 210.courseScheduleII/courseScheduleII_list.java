class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        int[] indegree = new int[numCourses];
        for (int[] p : prerequisites) {
            if (!graph.containsKey(p[1])) {
                graph.put(p[1], new ArrayList<>());
            }
            graph.get(p[1]).add(p[0]);
            indegree[p[0]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.offer(i);
        }
        
        int n = 0;
        int[] res = new int[numCourses];
        while (!q.isEmpty()) {
            int cur = q.poll();
            res[n++] = cur;
            List<Integer> neighbors = graph.containsKey(cur) ? graph.get(cur) : new ArrayList<>();
            for (int neighbor : neighbors) {
                if (--indegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }
        if (n == numCourses) return res;
        else return new int[]{};
    }
}
