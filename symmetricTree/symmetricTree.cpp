#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  bool isSymmetric(TreeNode *root) {
    if(!root)
      return true;
    else
      return helper(root->left, root->right);
  }
  bool helper(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true;
    else if (p && q) 
      return (p->val == q->val) && helper(p->left, q->right) && helper(p->right, q->left);
    else
      return false;
  }
};

int main()
{
  Solution s;
  int tree[7] = {1,2,2,9999,3,9999,3};
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
  
  cout << s.isSymmetric(vec[0]) << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
