/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        Map<Node, Node> m = new HashMap<>();
        Queue<Node> q = new LinkedList<>();
        q.offer(node);
        m.put(node, new Node(node.val));
        
        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (Node neighbor : cur.neighbors) {
                if (!m.containsKey(neighbor)) {
                    m.put(neighbor, new Node(neighbor.val));
                    q.offer(neighbor);
                }
            }
        }
        
        for (Map.Entry<Node, Node> entry : m.entrySet()) {
            Node n = entry.getKey(), nn = entry.getValue();
            for (Node neighbor : n.neighbors) {
                nn.neighbors.add(m.get(neighbor));
            }
        }
        
        return m.get(node);
    }
}
