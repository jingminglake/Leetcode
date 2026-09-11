#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  TreeNode* addOneRow(TreeNode *root, int v, int d) {
    if (d == 1) {
      TreeNode *t = new TreeNode(v);
      t->left = root;
      return t;
    }
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
      int size = q.size();
      depth++;
      for (int i = 0; i < size; i++) {
	TreeNode *temp = q.front();
	q.pop();
	TreeNode *tempLeft = temp->left;
	TreeNode *tempRight = temp->right;
	if (tempLeft)
	  q.push(tempLeft);
	if (tempRight)
	  q.push(tempRight);
	if (depth == d - 1) {
	  temp->left = new TreeNode(v);
	  temp->left->left = tempLeft;
	  temp->right = new TreeNode(v);
	  temp->right->right = tempRight;
	}
      }
    }
    return root;
  }
  void preorder(TreeNode *root) {
    if (!root)
      return;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    cout << root->val << " ";
    delete root;
    preorder(left);
    preorder(right);
  }
};

int main()
{
  Solution s;
  int tree[6] = {4,2,6,3,1,5};
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
  TreeNode* res = s.addOneRow(vec[0], 1, 2);
  s.preorder(res);
  cout << endl;
  vec.clear();
  return 0;
}
