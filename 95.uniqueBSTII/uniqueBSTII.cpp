#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  vector<TreeNode*> generateTrees(int n) {
    if (n < 1) {
      vector<TreeNode*> ans;
      return ans;
    }
    return generate(1, n);
  }
  vector<TreeNode*> generate(int start, int end) {
    vector<TreeNode*> list;
    if (start > end) {
      list.push_back(NULL);
      return list;
    }
    if (start == end) {
      list.push_back(new TreeNode(start));
      return list;
    }
    vector<TreeNode*> leftList, rightList;
    for (int i = start; i <= end; i++) {
      leftList = generate(start, i-1);
      rightList = generate(i+1, end);
      for (TreeNode *leftNode : leftList)
	for (TreeNode *rightNode : rightList) {
	  TreeNode *root = new TreeNode(i);
	  root->left = leftNode;
	  root->right = rightNode;
	  list.push_back(root);
	}
    }
    return list;
  }
  void preOrder(TreeNode* root) {
    if (!root)
      return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
};

int main()
{
  Solution s;
  int tree[3] = {5,2,13};
  int size = sizeof(tree)/sizeof(tree[0]);
  vector<TreeNode *> vec;
  for (int i = 0; i < size; i++) {
    if (tree[i] != 9999) {
      vec.push_back(new TreeNode(tree[i]));
    } else {
      vec.push_back(NULL);
    }
  }
  for (int i = 0; i < size/2; i++) {
    if(!vec[i])
      continue;
    if (i*2 + 1 < size)
      vec[i]->left = vec[i*2 + 1];
    if (i*2 + 2 < size)
      vec[i]->right = vec[i*2 + 2];
  }
  vector<TreeNode*> res = s.generateTrees(3);
  cout << res.size() << endl;
  for (TreeNode *t : res) {
    s.preOrder(t);
    cout << endl;
  }
  for (TreeNode *t : res) {
    delete t;
  }
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
