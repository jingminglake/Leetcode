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
    class Node {
        Node(TreeNode t, long index) {
            this.t = t;
            this.index = index;
        }
        TreeNode t;
        long index;
    }
    public int widthOfBinaryTree(TreeNode root) {
        int res = 0;
        if (root == null) return res;
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(root, 0));
        while (!q.isEmpty()) {
            int qSize = q.size();
            long left = 0, right = 0;
            for (int i = 0; i < qSize; i++) {
                Node n = q.poll();
                if (i == 0) {
                    left = n.index;
                }
                if (i == qSize - 1) {
                    right = n.index;
                }
                if (n.t.left != null) {
                    q.offer(new Node(n.t.left, n.index * 2 + 1));
                }
                if (n.t.right != null) {
                    q.offer(new Node(n.t.right, n.index * 2 + 2));
                }
            }
            res = Math.max(res, (int)(right - left + 1));
        }
        return res;
    }
}
