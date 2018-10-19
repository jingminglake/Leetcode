// javac InvertBinaryTree.java
// java InvertBinaryTree
import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

public class InvertBinaryTree {
    public TreeNode invertTree(TreeNode root) {
        if (root == null)
            return root;
        TreeNode left = invertTree(root.left);
        TreeNode right = invertTree(root.right);
        root.left = right;
        root.right = left;
        return root;
    }
	public static void main(String[] args) {
		int tree[] = {4,2,7,1,3,6,9};
		ArrayList<TreeNode> arrayList = new ArrayList<>();
		for (int i = 0; i < tree.length; i++) {
			if (tree[i] != 9999)
				arrayList.add(new TreeNode(tree[i]));
			else
				arrayList.add(null);
		}
		for (int i = 0; i < tree.length / 2; i++) {
			if (arrayList.get(i) == null)
				continue;
			if (i * 2 + 1 < tree.length)
				arrayList.get(i).left = arrayList.get(i * 2 + 1);
			if (i * 2 + 2 < tree.length)
				arrayList.get(i).right = arrayList.get(i * 2 + 2);
		}
		InvertBinaryTree s = new InvertBinaryTree();
		TreeNode root = s.invertTree(arrayList.get(0));
		Queue<TreeNode> q = new LinkedList<TreeNode>();
		q.offer(root);
		while (q.size() != 0) {
			TreeNode t = q.poll();
			System.out.print(t.val + " ");
			if (t.left != null)
				q.offer(t.left);
			if (t.right != null)
				q.offer(t.right);
		}
		System.out.println();
	}
}
