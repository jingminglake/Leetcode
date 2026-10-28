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
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        // do same check at root
        if (isSameTree(root, subRoot)) return true;
        // subquery in left and right
        if (root == null) return false;
        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }

    public boolean isSameTree(TreeNode r1, TreeNode r2) {
        if (r1 == null && r2 == null) return true;
        else if (r1 == null || r2 == null) return false;
        return r1.val == r2.val && isSameTree(r1.left, r2.left) && isSameTree(r1.right, r2.right);
    }
}

/*

     1       3
    /
   2
  /
 3
expected: true

isSubtree(1, 3):
  isSameTree(1, 3) → false
  isSubtree(1 的左 = 2, 3)
    isSameTree(2, 3) → false
    isSubtree(2 的左 = 3, 3):
      isSameTree(3, 3) → true


root=[1,2]、subRoot=[1]
isSubTree([1, 2], [1]):
   isSameTree([1, 2], [1]) -> false
   isSubTree(1的左[2], [1]):
     isSameTree([2], [1]) -> false
     isSubTree(2的左nul, [1]) -> false
   isSameTree(1的右null, [1]) -> false
-> false
*/