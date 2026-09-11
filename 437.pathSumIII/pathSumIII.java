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
    int res = 0;
    public int pathSum(TreeNode root, int targetSum) {
        res = 0;
        if (root == null) return res;
        Map<Integer, Integer> preSum = new HashMap<>();
        preSum.put(0, 1);
        int path = 0;
        dfs(root, targetSum, preSum, path);
        return res;
    }
    
    public void dfs(TreeNode root, int targetSum, Map<Integer, Integer> preSum, int path) {
        if (root == null) return;
        path += root.val;
        if (preSum.containsKey(path - targetSum)) {
            res += preSum.get(path - targetSum);
        }
        if (preSum.containsKey(path)) {
            preSum.put(path, preSum.get(path) + 1);
        } else {
            preSum.put(path, 1);
        }
        dfs(root.left, targetSum, preSum, path);
        dfs(root.right, targetSum, preSum, path);
        preSum.put(path, preSum.get(path) - 1);
    }
}
