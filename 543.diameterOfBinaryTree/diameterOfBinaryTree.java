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
    private int global;
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        // return: root + left or right
        helper(root);
        return global - 1;
    }

    private int helper(TreeNode root) {
        if (root == null) return 0;
        int leftRes = helper(root.left);
        int rightRes = helper(root.right);
        
        int res = Math.max(leftRes, rightRes) + 1;
        global = Math.max(global, leftRes + rightRes + 1);
        return res;
    }
}

/*

      1
     /
    2
   / \
  3   4
 /     \
5       6

5 -> leftRes=0, rightRes=0, res=1, global=1

3 -> leftRes=1, rightRes=0, res=2, global=2

6 -> leftRes=0, rightRes=0, res=1, global=2

4 -> leftRes=0, rightRes=1, res=1, global=2

2 -> leftRes=2, rightRes=2, res=3, global=5

1 -> leftRes=3, rightRes=0, res=4, global=5

global - 1 == 4

 */