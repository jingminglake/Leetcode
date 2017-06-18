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
  TreeNode* invertTree(TreeNode *root) {
    /* if (!root)
      return NULL;
    TreeNode *t = new TreeNode(root->val);
    t->left = invertTree(root->right);
    t->right = invertTree(root->left);
    return t; */
    if (!root)
      return NULL;
    TreeNode *temp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = temp;
    return root;
  }
};

int main()
{
  Solution s;
  int tree[7] = {4,2,7,1,3,6,9};
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
    if (i*2 + 1 < size)
      vec[i]->left = vec[i*2 + 1];
    if (i*2 + 2 < size)
      vec[i]->right = vec[i*2 + 2];
  }
  TreeNode *root = s.invertTree(vec[0]);
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *t = q.front();
    cout << t->val << " ";
    q.pop();
    if (t->left)
      q.push(t->left);
    if (t->right)
      q.push(t->right);
    //delete t; 
  }
  cout << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
