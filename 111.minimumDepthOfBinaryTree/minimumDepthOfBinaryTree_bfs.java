/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null)
            return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int depth = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode t = q.poll();
                if (t.left == null && t.right == null) {
                    return depth;
                }
                if (t.left != null)
                    q.offer(t.left);
                if (t.right != null)
                    q.offer(t.right);
            }
        }
        return depth;
    }
}
