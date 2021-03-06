class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        for (int[] pre : prerequisites) {
            if (!graph.containsKey(pre[1])) {
                graph.put(pre[1], new HashSet<>());
            }
            graph.get(pre[1]).add(pre[0]);
        }
        int[] indegree = new int[numCourses];
        for (Set<Integer> s : graph.values()) {
            for (Integer i : s) indegree[i]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < indegree.length; i++) {
            if (indegree[i] == 0) q.offer(i);
        }
        int visitedNum = 0;
        while (!q.isEmpty()) {
            Integer node = q.poll();
            visitedNum++;
            Set<Integer> neighbors = graph.containsKey(node) ? graph.get(node) : new HashSet<>();
            for (Integer neighbor : neighbors) {
                if (--indegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }
        return visitedNum == numCourses;
    }
}
