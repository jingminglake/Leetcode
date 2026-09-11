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
  TreeNode* deleteNode(TreeNode *root, int key) {
    if (!root)
      return NULL;
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
      return root;
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
      return root;
    } else {
      TreeNode *leftChild = root->left;
      TreeNode *rightChild = root->right;
      TreeNode *tempL = leftChild;
      delete root;
      if (!leftChild)
	return rightChild;
      if (!rightChild)
	return leftChild;
      TreeNode *minNode = findPre(tempL);
      minNode->right = rightChild->left;
      rightChild->left = leftChild;
      return rightChild;
    }
  }

  TreeNode* findPre(TreeNode *node) {
    while (node->right) {
      node = node->right;
    }
    return node;
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
  int tree[7] = {5,3,6,2,4,9999,7};
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
  TreeNode* res = s.deleteNode(vec[0], 3);
  cout << "res-->" << res->val << endl;
  s.preorder(vec[0]);
  cout << endl;
  vec.clear();
  return 0;
}
