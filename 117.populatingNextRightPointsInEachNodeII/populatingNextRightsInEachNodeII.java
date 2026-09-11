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
            levelHead = null;
            Node last = null;
            while (cur != null) {
                if (cur.left != null) {
                    if (last != null) {
                        last.next = cur.left;
                    } else {
                        levelHead = cur.left;
                    }
                    last = cur.left;
                }
                if (cur.right != null) {
                    if (last != null) {
                        last.next = cur.right;
                    } else {
                        levelHead = cur.right;
                    }
                    last = cur.right;
                }
                cur = cur.next;
            }
        }
        return root;
    }
}
