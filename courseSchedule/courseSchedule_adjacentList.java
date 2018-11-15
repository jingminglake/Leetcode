class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if(numCourses <= 0)
            return false;
        if(prerequisites == null || prerequisites.length == 0)
            return true;
        Map<Integer, Set<Integer> > graph = new HashMap<>();
        for (int i = 0; i < prerequisites.length; i++) {
            //System.out.println("++++++" + prerequisites[i][1] + "++++" + prerequisites[i][0]);
            graph.putIfAbsent(prerequisites[i][1], new HashSet<Integer>());
            graph.get(prerequisites[i][1]).add(prerequisites[i][0]);
        }
        //System.out.println("+++" + graph.size());
        int[] indegree = new int[numCourses];
        for (Set<Integer> s : graph.values()) {
            //System.out.println("====");
            for (Integer i : s) {
                indegree[i]++;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < indegree.length; i++) {
            //System.out.print(indegree[i]);
            if (indegree[i] == 0)
                q.offer(i);
        }
        int num = 0;
        while (!q.isEmpty()) {
            int node = q.poll();
            num++;
            for (Integer n : graph.getOrDefault(node, new HashSet<Integer>()) ) {
                if (--indegree[n] == 0)
                    q.offer(n);
            }
        }
        return numCourses == num;
    }
}
