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
    private int cur;
    private int kth;
    public int kthSmallest(TreeNode root, int k) {
        cur = 0;
        inorder(root, k);
        return kth;
    }

    private void inorder(TreeNode root, int k) {
        if (root == null || cur >= k) return;
        inorder(root.left, k);
        cur++;
        if (cur == k) {
            kth = root.val;
            return;
        }
        inorder(root.right, k);
    }
}