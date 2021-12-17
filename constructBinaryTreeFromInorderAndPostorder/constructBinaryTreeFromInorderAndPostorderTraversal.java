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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        Map<Integer, Integer> inorderIndex = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inorderIndex.put(inorder[i], i);
        }
        return buildTreeHelper(inorder, postorder, 0, inorder.length - 1, 0, postorder.length - 1, inorderIndex);
    }
    
    public TreeNode buildTreeHelper(int[] inorder, int[] postorder, int iStart, int iEnd, int pStart, int pEnd, Map<Integer, Integer> inorderIndex) {
        if (iStart > iEnd) return null;
        TreeNode root = new TreeNode(postorder[pEnd]);
        int pivot = inorderIndex.get(root.val);
        root.left = buildTreeHelper(inorder, postorder, iStart, pivot - 1, pStart, pEnd - iEnd + pivot - 1, inorderIndex);
        root.right = buildTreeHelper(inorder, postorder, pivot + 1, iEnd, pEnd - iEnd + pivot, pEnd - 1, inorderIndex);
        return root;
    }
}
