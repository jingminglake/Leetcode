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
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> stk = new Stack<>();
        TreeNode cur = root;
        int index = 0;
        while (cur != null || !stk.isEmpty()) {
            while (cur != null) {
                stk.add(cur);
                cur = cur.left;
            }

            // visit
            TreeNode node = stk.pop();
            index++;
            if (index == k) return node.val;

            // visit right
            cur = node.right;
        }
        return -1;
    }
}
