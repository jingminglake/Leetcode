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
    public int rob(TreeNode root) {
        int[] res = robHelper(root);
        return Math.max(res[0], res[1]);
    }
    
    public int[] robHelper(TreeNode root) {
        int[] res = new int[2]; // 0 -> must rob, 1 -> must not rob
        if (root == null) return res;
        int[] leftRes = robHelper(root.left);
        int[] rightRes = robHelper(root.right);
        res[0] = root.val + leftRes[1] + rightRes[1];
        res[1] = Math.max(leftRes[0], leftRes[1]) + Math.max(rightRes[0], rightRes[1]);
        return res;
    }
}
