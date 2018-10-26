import java.util.*;
class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}
public class PrintBinaryTree {
    class Params {
        Params(TreeNode _root, int _l, int _r) {
            root = _root;
            l = _l;
            r = _r;
        }
        TreeNode root;
        int l, r;
    }
    public List<List<String>> printTree(TreeNode root) {
        int h = getHeight(root);
        int w = (int) Math.pow(2, h) - 1;
        List<List<String>> res = new ArrayList<>();
        String[][] ans = new String[h][w];
        for (String[] arr : ans)
            Arrays.fill(arr, "");
        bfs(ans, root, w);
        for (String[] arr : ans)
            res.add(Arrays.asList(arr));
        return res;
            
    }
    public void bfs(String[][] ans, TreeNode root, int w) {
        Queue<Params> q = new LinkedList();
        q.add(new Params(root, 0, w - 1));
        int level = 0;
        while (!q.isEmpty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                Params p = q.remove();
                int pos = (p.l + p.r) / 2;
                ans[level][pos] = "" + p.root.val;
                if (p.root.left != null)
                    q.add(new Params(p.root.left, p.l, pos - 1));
                if (p.root.right != null)
                    q.add(new Params(p.root.right, pos + 1, p.r));
            }
            level++;
        }
    }
    public int getHeight(TreeNode root) {
        if (root == null) return 0;
        return Math.max(getHeight(root.left), getHeight(root.right)) + 1;
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
		PrintBinaryTree s = new PrintBinaryTree();
		for (List<String> arr : s.printTree(arrayList.get(0))) {
			for (String ss : arr) {
				if (ss.equals("")) {
					System.out.print("\"\",");
				} else { 
					System.out.print("\"" + ss + "\",");
				}
			}
			System.out.println();
		}
	}
}
