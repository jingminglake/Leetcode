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
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        List<TreeNode> res = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        findDuplicateSubtreesHelper(root, map, res);
        return res;
    }
    
    public String findDuplicateSubtreesHelper(TreeNode root, Map<String, Integer> map, List<TreeNode> res) {
        if (root == null) return "#";
        StringBuilder sb = new StringBuilder();
        String uniqueOrder = String.valueOf(root.val) + "," + findDuplicateSubtreesHelper(root.left, map, res) +  "," + findDuplicateSubtreesHelper(root.right, map, res);
        if (map.containsKey(uniqueOrder)) {
            int num = map.get(uniqueOrder);
            if (num == 1) res.add(root);
            map.put(uniqueOrder, num + 1);
        } else {
            map.put(uniqueOrder, 1);
        }
        return uniqueOrder;
    }
}
