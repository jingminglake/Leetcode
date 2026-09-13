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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int qSize = q.size();

            for (int i = 0; i < qSize; i++) {
                TreeNode n = q.poll();
                if (n.left != null) q.add(n.left);
                if (n.right != null) q.add(n.right);
                if (i == qSize - 1) {
                    res.add(n.val);
                }
            }
        }
        return res;
    }
}