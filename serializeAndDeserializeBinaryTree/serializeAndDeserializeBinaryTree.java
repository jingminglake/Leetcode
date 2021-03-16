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
        if (root == null) return "#,";
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        sb.append(root.val).append(",");
        while (!q.isEmpty()) {
            TreeNode cur = q.poll();
            if (cur.left != null) {
                q.offer(cur.left);
                sb.append(cur.left.val).append(",");
            } else {
                sb.append("#,");
            }
            if (cur.right != null) {
                q.offer(cur.right);
                sb.append(cur.right.val).append(",");
            } else {
                sb.append("#,");
            }
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] nodes = data.split(",");
        if (nodes.length <= 2) return null;
        Queue<TreeNode> q = new LinkedList<>();
        int index = 0;
        TreeNode root = new TreeNode(Integer.valueOf(nodes[index++]));
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode cur = q.poll();
            String leftV = nodes[index++];
            if (!leftV.equals("#")) {
                TreeNode left = new TreeNode(Integer.valueOf(leftV));
                cur.left = left;
                q.offer(left);
            }
            String rightV = nodes[index++];
            if (!rightV.equals("#")) {
                TreeNode right = new TreeNode(Integer.valueOf(rightV));
                cur.right = right;
                q.offer(right);
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
