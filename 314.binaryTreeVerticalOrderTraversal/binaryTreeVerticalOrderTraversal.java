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
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) return res;
        Map<Integer, List<Integer>> cols = new HashMap<>();
        Queue<TreeNode> q = new LinkedList<>();
        Queue<Integer> qc = new LinkedList<>();
        q.offer(root);
        qc.offer(0);
        int minC = 0, maxC = 0;

        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            int c = qc.poll();
            cols.computeIfAbsent(c, x -> new ArrayList<>()).add(node.val);
            minC = Math.min(minC, c);
            maxC = Math.max(maxC, c);
            if (node.left != null) {
                q.offer(node.left);
                qc.offer(c - 1);
            }
            if (node.right != null) {
                q.offer(node.right);
                qc.offer(c + 1);
            }
        }
        for (int c = minC; c <= maxC; c++) res.add(cols.get(c));
        return res;
    }
}