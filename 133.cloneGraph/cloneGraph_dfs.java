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
        Map<Node, Node> oldToNew = new HashMap<>();
        cloneNode(node, oldToNew);

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

    private void cloneNode(Node node, Map<Node, Node> oldToNew) {
        if (node == null) return;
        if (oldToNew.containsKey(node)) return;
        Node newNode = new Node(node.val);
        // put before visiting neighbors, so a cycle back to node returns immediately
        oldToNew.put(node, newNode);
        
        for (Node n : node.neighbors) {
            cloneNode(n, oldToNew);
        }
    }
}

/*
val = 1, adjList[[]]
oldToNew : cloneNode node1 -> node1'
           clone edges -->
return oldToNew(node1) --> node1'

val = 1, adjList[[2,4],[1,3],[2,4],[1,3]]
oldToNew : cloneNode node1 -> node1', node2 -> node2', node3 -> node3', node4 -> node4'
           clone edges --> node1 --> node1' 1->2 1->4, 1'->oldToNew(2)=2', 1'-> oldToNew(4)=4'
                           node2 --> node2', 2->1, 2->3, 2'->oldToNew(1)=1', 2' -> oldToNew(3)=3'
                           ...
return oldToNew(node1) --> node1'

[[2],[1]]	[[2],[1]]
cloneNode(1): 不是 null；map 里没有 1 → 创建 1'，put(1→1')
  遍历 1 的邻居：
  cloneNode(2): 不是null；map里面没有2 -> 创建 2'. put(2->2')
    遍历 2 的邻居：
    cloneNode(1): 不是null，map里面有1  -> return


*/