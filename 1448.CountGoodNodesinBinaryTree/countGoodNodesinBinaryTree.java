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
    int res;
    public int goodNodes(TreeNode root) {
        goodNodesHelper(root, root.val);
        return res;
    }

    private void goodNodesHelper(TreeNode root, int maxSoFar) {
        if (root == null) return;
        if (root.val >= maxSoFar) {
            res++;
            maxSoFar = root.val;
        }
        goodNodesHelper(root.left, maxSoFar);
        goodNodesHelper(root.right, maxSoFar);
    }

    /*
    root = [3,1,4,3,null,1,5]
    (3, 3)
        res=1 maxSoFar=3 left (1, 3)
                    1 >= 3? false; res = 1; left (3, 3)
                                            3 == 3? true; res = 2; left(null, 3) ->return
                    right (1, null) -> return
        res=2 maxSoFar=3 right(4, 3)
                    4 >= 3? true; res = 3; left(1, 4) 
                                            1>=4? false left(null, 4), right(null, 4) -> return
                                           right(5, 4)
                                           5 >= 4? true; res = 4; left(null, 5), right(null, 5) -> return
    */
}