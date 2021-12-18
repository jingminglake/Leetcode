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
    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> set = new HashSet<Integer>();
        return findTargetHelper(root, k, set);
    }
    
    public boolean findTargetHelper(TreeNode root, int k, Set<Integer> set) {
        if (root == null) return false;
        if (set.contains(root.val)) return true;
        set.add(k - root.val);
        return findTargetHelper(root.left, k, set) || findTargetHelper(root.right, k, set);
    }
}
