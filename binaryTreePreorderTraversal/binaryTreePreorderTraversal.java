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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<Integer>();
        if (root == null) return res;
        Stack<TreeNode> stk = new Stack<TreeNode>();
        stk.add(root);
        while (!stk.isEmpty()) {
            TreeNode cur = stk.pop(); // current handling node
            res.add(cur.val);
            if (cur.right != null) {
                stk.add(cur.right);
            }
            if (cur.left != null) {
                stk.add(cur.left);
            }
        }
        return res;
    }
}
