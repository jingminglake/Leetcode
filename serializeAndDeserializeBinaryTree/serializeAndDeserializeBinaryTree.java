/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        if (root == null) return sb.toString();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode cur = q.poll();
            if (cur != null) {
                sb.append(String.valueOf(cur.val)).append(",");
                q.offer(cur.left);
                q.offer(cur.right);
            } else {
                sb.append("#,");
            }
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || data.length() == 0) return null;
        String[] vals = data.split(",");
        Queue<TreeNode> q = new LinkedList<>();
        TreeNode root = new TreeNode(Integer.parseInt(vals[0]));
        q.offer(root);
        for (int i = 1; i < vals.length; i += 2) {
            TreeNode cur = q.poll();
            if (!vals[i].equals("#")) {
                TreeNode left = new TreeNode(Integer.parseInt(vals[i]));
                q.add(left);
                cur.left = left;
            }
            if (!vals[i + 1].equals("#")) {
                TreeNode right = new TreeNode(Integer.parseInt(vals[i + 1]));
                q.add(right);
                cur.right = right;
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
