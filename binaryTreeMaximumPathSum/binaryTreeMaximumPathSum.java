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
    int maxSum = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        maxPathSumHelper(root);
        return maxSum;
    }
    
    public int maxPathSumHelper(TreeNode root) {
        if (root == null) return Integer.MIN_VALUE;
        int notPassRootRes = root.val;
        int leftRes = maxPathSumHelper(root.left);
        int rightRes = maxPathSumHelper(root.right);
        if (leftRes > 0 && rightRes > 0) {
            notPassRootRes = Math.max(notPassRootRes, Math.max(leftRes, rightRes) + root.val);
            maxSum = Math.max(maxSum, leftRes + rightRes + root.val);
        } else if (leftRes > 0) {
            notPassRootRes = Math.max(notPassRootRes, leftRes + root.val);
            maxSum = Math.max(maxSum, notPassRootRes);
        } else if (rightRes > 0) {
            notPassRootRes = Math.max(notPassRootRes, rightRes + root.val);
            maxSum = Math.max(maxSum, notPassRootRes);
        } else {
            maxSum = Math.max(maxSum, root.val);
        }
        return notPassRootRes;
    }
}
