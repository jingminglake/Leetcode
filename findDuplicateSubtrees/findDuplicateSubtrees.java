/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        List<TreeNode> res = new LinkedList<>();
        Map<String, Integer> m = new HashMap<>();
        traverse(root, m, res);
        return res;
    }
    public String traverse(TreeNode root, Map<String, Integer> m, List<TreeNode> res) {
        if (root == null)
            return "#";
        String str = root.val + traverse(root.left, m, res) + traverse(root.right, m, res);
        if (m.getOrDefault(str, 0) == 1)
            res.add(root);
        m.put(str, m.getOrDefault(str, 0) + 1);
        return str;
    }
}
