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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        Map<Integer, Integer> valToIndex = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            valToIndex.put(inorder[i], i);
        }

        return buildHelper(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1, valToIndex);
    }

    private TreeNode buildHelper(int[] preorder, int[] inorder, int pStart, int pEnd, int iStart, int iEnd, Map<Integer, Integer> valToIndex) {
        if (pStart > pEnd) return null;
        if (pStart == pEnd) return new TreeNode(preorder[pStart]);
        TreeNode res = new TreeNode(preorder[pStart]);
        int x = valToIndex.get(preorder[pStart]);
        int leftSize = x - iStart;
        res.left = buildHelper(preorder, inorder, pStart + 1, pStart + leftSize, iStart, x - 1, valToIndex);
        res.right = buildHelper(preorder, inorder, pStart + leftSize + 1, pEnd, x + 1, iEnd, valToIndex);
        return res;
    }
}