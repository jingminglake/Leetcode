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
        if (node == null)
            return null;
        Map<Node, Node> oldToNew = new HashMap<>();

        // clone node
        bfs(node, oldToNew);

        // clone edges
        for (Map.Entry<Node, Node> entry : oldToNew.entrySet()) {
            Node oldN = entry.getKey();
            Node newN = entry.getValue();
            for (Node n : oldN.neighbors) {
                newN.neighbors.add(oldToNew.get(n));
            }
        }
        return oldToNew.get(node);
    }

    private void bfs(Node node, Map<Node, Node> oldToNew) {
        Queue<Node> q = new LinkedList<>();
        q.add(node);
        oldToNew.put(node, new Node(node.val));
        while (!q.isEmpty()) {
            Node peek = q.poll();
            for (Node n : peek.neighbors) {
                if (oldToNew.containsKey(n))
                    continue;
                q.add(n);
                oldToNew.put(n, new Node(n.val));
            }
        }
    }
}