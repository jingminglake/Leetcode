class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        List<String> res = new ArrayList<String>();
        Map<String, PriorityQueue<String>> graph = new HashMap<>();
        for (List<String> ticket : tickets) {
            if (!graph.containsKey(ticket.get(0))) {
                graph.put(ticket.get(0), new PriorityQueue<String>());
            }
            graph.get(ticket.get(0)).add(ticket.get(1));
        }
        dfs(res, graph, "JFK");
        Collections.reverse(res);
        return res;
    }
    
    void dfs(List<String> res, Map<String, PriorityQueue<String>> graph, String startNode) {
        while (graph.containsKey(startNode) && !graph.get(startNode).isEmpty()) {
            dfs(res, graph, graph.get(startNode).poll());
        }
        res.add(startNode);
    }
}