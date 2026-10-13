class Solution {
    static class Edge {
        int to;
        double prob;
        Edge(int to, double prob) {
            this.to = to;
            this.prob = prob;
        }
    }

    static class State {
        int node;
        double prob;
        State(int node, double prob) {
            this.node = node;
            this.prob = prob;
        }
    }

    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        // build graph
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edges.length; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double p = succProb[i];

            graph.get(a).add(new Edge(b, p));
            graph.get(b).add(new Edge(a, p));
        }
        // init prob dist array and heap
        double[] probDist = new double[n];
        probDist[start_node] = 1.0;

        PriorityQueue<State> pq = new PriorityQueue<>((a, b) -> Double.compare(b.prob, a.prob));
        pq.offer(new State(start_node, 1.0));
        
        // Dijkstra
        while (!pq.isEmpty()) {
            State cur = pq.poll();
            int u = cur.node;
            double p = cur.prob;

            if (p < probDist[u]) continue; //outdate

            if (u == end_node) return p;

            for (Edge edge : graph.get(u)) {
                int v = edge.to;
                double newProb = p * edge.prob;

                if (newProb > probDist[v]) {
                    probDist[v] = newProb;
                    pq.offer(new State(v, probDist[v]));
                }
                
            }
        }
        return 0.0;
    }
}