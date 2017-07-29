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
  void flatten(TreeNode *root) {
    vector<TreeNode*> vec;
    preorder(root, vec);
    TreeNode *r = root;
    for (int i = 1; i < vec.size(); i++) {
      r->left = NULL;
      r->right = vec[i];
      r = r->right;
    }
  }
  void preorder(TreeNode *root, vector<TreeNode*>& vec) {
    if (!root)
      return;
    vec.push_back(root);
    preorder(root->left, vec);
    preorder(root->right, vec);
  }
};

int main()
{
  Solution s;
  int tree[12] = {1,2,3,4,9999,5,6,9999,9999,9999,9999,7};
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
  s.flatten(vec[0]);
  TreeNode *tn = vec[0];
  while (tn) {
    cout << tn->val << " ";
    tn = tn->right;
  }
  cout << endl;
  for (TreeNode *t : vec) {
    //cout << t->val << " ";
    delete t;
  }
  vec.clear();
  return 0;
}
