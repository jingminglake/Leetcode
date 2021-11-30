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
    public int res = 0;
    public int longestUnivaluePath(TreeNode root) {
        if (root == null) return 0;
        res = 0;
        pathHelper(root);
        return res;
    }
    
    public int pathHelper(TreeNode root) {
        if (root == null) return 0;
        int leftRes = pathHelper(root.left);
        int rightRes = pathHelper(root.right);
        int leftConnect = 0, rightConnect = 0;
        if (root.left != null && root.left.val == root.val) {
            leftConnect = leftRes + 1;
        }
        if (root.right != null && root.right.val == root.val) {
            rightConnect = rightRes + 1;
        }
        res = Math.max(res, leftConnect + rightConnect);
        return Math.max(leftConnect, rightConnect);
    }
}
