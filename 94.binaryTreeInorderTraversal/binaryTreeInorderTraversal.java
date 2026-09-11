/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public class Node {
        Node(TreeNode t, int op) {
            this.t = t;
            this.op = op;
        }
        TreeNode t;
        int op; // 0 -> print, 1 -> visit
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<Integer>();
        if (root == null) return res;
        Stack<Node> stk = new Stack<Node>();
        stk.add(new Node(root, 1));
        while (!stk.isEmpty()) {
            Node n = stk.pop();
            if (n.op == 0) {
                res.add(n.t.val);
            } else if (n.op == 1) {
                if (n.t.right != null) stk.add(new Node(n.t.right, 1));
                stk.add(new Node(n.t, 0));
                if (n.t.left != null) stk.add(new Node(n.t.left, 1));
            }
        }
        return res;
    }
}
