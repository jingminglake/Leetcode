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
    long global;
    public int maxPathSum(TreeNode root) {
        global = Integer.MIN_VALUE;
        // {1: root + left or right; 2: root only }
        helper(root);
        return (int)global;
    }

    private long helper(TreeNode root) {
        if (root == null) return Integer.MIN_VALUE;
        long leftRes = helper(root.left);
        long rightRes = helper(root.right);

        long res1 = root.val;
        long res2 = root.val + Math.max(leftRes, rightRes);

        global = Math.max(global, res1);
        global = Math.max(global, res2);
        global = Math.max(global, root.val + leftRes + rightRes);

        return Math.max(res1, res2);
    }

    /*
    ex1: root = [-1]
    leftRes = min, rightRes = min
    res1: -1; res2: min - 1 return -1; global: -1

    ex2: root = [1]
    leftRes = min, rightRes = min
    res1: 1, res2: min+1, return 1, global: 1

    ex3: root = [-10,9,20,null,null,15,7]
    9: return 9. global 9
    15: return 15, global 15
    7: return 7, global 15
    20: return 35, global 42
    -10: return 25, global 42
    */
}