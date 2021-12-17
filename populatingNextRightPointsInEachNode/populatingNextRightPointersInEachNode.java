/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if (root == null) return root;
        Node levelHead = root;
        while (levelHead != null) {
            Node cur = levelHead;
            Node last = null;
            while (cur != null) {
                if (cur.left != null && cur.right != null) {
                    if (last != null) {
                        last.next = cur.left;
                    }
                    last = cur.right;
                    cur.left.next = cur.right;
                }
                cur = cur.next;
            }
            levelHead = levelHead.left;
        }
        return root;
    }
}
