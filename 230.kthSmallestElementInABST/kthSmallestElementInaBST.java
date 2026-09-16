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
        Map<TreeNode, Integer> mSize = new HashMap<>();
        computeSize(root, mSize);

        return kthSamllestHelper(root, k, mSize);
    }

    private int kthSamllestHelper(TreeNode root, int k, Map<TreeNode, Integer> mSize) {
        if (root == null) return 0;
        int sizeLeft = root.left != null ? mSize.get(root.left) : 0;
        if (sizeLeft + 1 == k) { 
            return root.val;
        } else if (sizeLeft + 1 > k) {
            return kthSamllestHelper(root.left, k, mSize);
        } else {
            return kthSamllestHelper(root.right, k - sizeLeft - 1, mSize);
        }
    }

    private int computeSize(TreeNode root, Map<TreeNode, Integer> mSize) {
        if (root == null) return 0;
        int leftRes = computeSize(root.left, mSize);
        int rightRes = computeSize(root.right, mSize);
        int res = leftRes + rightRes + 1;
        mSize.put(root, res);
        return res;
    }
}
