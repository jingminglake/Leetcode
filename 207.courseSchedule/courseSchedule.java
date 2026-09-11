class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
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
        
        int n = numCourses;
        while (!q.isEmpty()) {
            int cur = q.poll();
            n--;
            List<Integer> neighbors = graph.containsKey(cur) ? graph.get(cur) : new ArrayList<>();
            for (int neighbor : neighbors) {
                if (--indegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }
        return n == 0;
    }
}
