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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        List<Integer> level = new ArrayList<>();
        level.add(root.val);
        res.add(level);
        while (!q.isEmpty()) {
            int q_size = q.size();
            level = new ArrayList<>();
            for (int i = 0; i < q_size; i++) {
                TreeNode n = q.poll();
                if (n.left != null) {
                    level.add(n.left.val);
                    q.offer(n.left);
                }
                if (n.right != null) {
                    level.add(n.right.val);
                    q.offer(n.right);
                }
            }
            if (!level.isEmpty()) res.add(level);
        }
        return res;
    }
}
