class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        List<String> itinerary = new LinkedList<>();
        Map<String, PriorityQueue<String> > graph = new HashMap<>();
        for (List<String> ticket : tickets) {
            if (!graph.containsKey(ticket.get(0))) {
                graph.put(ticket.get(0), new PriorityQueue<String>());
            }
            graph.get(ticket.get(0)).add(ticket.get(1));
        }
        dfs(graph, itinerary, "JFK");
        return itinerary;
    }
    public void dfs(Map<String, PriorityQueue<String> > graph, List<String> itinerary, String startNode) {
        while (graph.containsKey(startNode) && !graph.get(startNode).isEmpty()) {
            dfs(graph, itinerary, graph.get(startNode).poll());
        }
        itinerary.add(0, startNode);
    }
}