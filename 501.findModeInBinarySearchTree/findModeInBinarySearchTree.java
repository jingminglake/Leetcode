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
    long preVal = Long.MIN_VALUE;
    int count = 1;
    int maxCount = 1;
    public int[] findMode(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        count = 1;
        maxCount = 1;
        preVal = Long.MIN_VALUE;
        findModeHelper(root, res);
        int[] mode = new int[res.size()];
        for (int i = 0; i < res.size(); i++) mode[i] = res.get(i);
        return mode;
    }
    
    public void findModeHelper(TreeNode root, List<Integer> res) {
        if (root == null) return;
        findModeHelper(root.left, res);
        if (root.val == preVal) {
            count++;
        } else {
            count = 1;
        }
        if (count == maxCount) {
            res.add(root.val);
        } else if (count > maxCount) {
            maxCount = count;
            res.clear();
            res.add(root.val);
        }
        preVal = root.val;
        findModeHelper(root.right, res);
    }
}
