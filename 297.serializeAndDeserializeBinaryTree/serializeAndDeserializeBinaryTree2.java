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

    private static final String NONE = "#";
    private static final String SEP = ",";

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serializeTree(root, sb);
        return sb.toString();
    }

    private void serializeTree(TreeNode node, StringBuilder sb) {
        if (node == null) {
            sb.append(NONE).append(SEP);
            return;
        }
        sb.append(node.val).append(SEP);
        serializeTree(node.left, sb);
        serializeTree(node.right, sb);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || data.isEmpty()) return null;

        Deque<String> tokens = new ArrayDeque<>();
        for (String d : data.split(SEP)) {
            tokens.addLast(d);
        }

        return deserializeTree(tokens);
    }

    private TreeNode deserializeTree(Deque<String> tokens) {
        if (tokens.isEmpty()) return null;
        String token = tokens.removeFirst();

        if (token.equals(NONE)) return null;

        TreeNode node = new TreeNode(Integer.parseInt(token));

        node.left = deserializeTree(tokens);
        node.right = deserializeTree(tokens);
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));