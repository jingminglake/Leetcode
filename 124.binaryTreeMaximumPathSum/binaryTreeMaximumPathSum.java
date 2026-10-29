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
    int global;
    public int maxPathSum(TreeNode root) {
        global = Integer.MIN_VALUE;
        // {1: root + left or right; 2: root only }
        helper(root);
        return global;
    }

    private int helper(TreeNode root) {
        if (root == null) return 0;
        int leftRes = helper(root.left);
        int rightRes = helper(root.right);

        int leftPart = Math.max(0, leftRes);
        int rightPart = Math.max(0, rightRes);

        int res = root.val + Math.max(leftPart, rightPart);

        global = Math.max(global, res);
        global = Math.max(global, root.val + leftPart + rightPart);

        return res;
    }
}