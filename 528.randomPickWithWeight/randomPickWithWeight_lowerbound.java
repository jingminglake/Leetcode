class Solution {

    public Solution(int[] w) {
        random = new Random();
        preSum = new int[w.length];
        preSum[0] = w[0];
        for (int i = 1; i < w.length; i++) {
            preSum[i] = preSum[i - 1] + w[i];
        }
        root = buildTree(0, w.length - 1);
    }
    
    public int pickIndex() {
        int len = preSum.length;
        if (len == 1) return 0;
        int n = random.nextInt(preSum[len - 1]) + 1;
        TreeNode lb = findLowerBound(n);
        return lb.index;
    }
    
    private TreeNode findLowerBound(int n) {
        TreeNode lb = null;
        TreeNode cur = root;
        while (cur != null) {
            if (preSum[cur.index] < n) {
                cur = cur.right;
            } else {
                lb = cur;
                cur = cur.left;
            }
        }
        return lb;
    }
    
    private TreeNode buildTree(int left, int right) {
        if (left > right) return null;
        int mid = left + (right - left) / 2;
        TreeNode root = new TreeNode(mid);
        root.left = buildTree(left, mid - 1);
        root.right = buildTree(mid + 1, right);
        return root;
    }
    
    private int[] preSum;
    Random random;
    TreeNode root;
}

class TreeNode {
    public TreeNode(int index) { this.index = index; }
    TreeNode left;
    TreeNode right;
    int index;
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
