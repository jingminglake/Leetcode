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
class BSTIterator {

    public BSTIterator(TreeNode root) {
        s = new Stack<>();
        putLeftChildToStack(root);
    }
    
    public int next() {
        if (hasNext()) {
            TreeNode t = s.pop();
            if (t.right != null) {
                putLeftChildToStack(t.right);
            }
            return t.val;
        }
        return -1;
    }
    
    public boolean hasNext() {
        return !s.isEmpty();
    }
    
    private void putLeftChildToStack(TreeNode t) {
        while (t != null) {
            s.push(t);
            t = t.left;
        }
    }
    
    Stack<TreeNode> s;
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
