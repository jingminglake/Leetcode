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
  TreeNode* convertBST(TreeNode *root) {
    int preSum = 0;
    reInorder(root, preSum);
    return root;
  }
  void reInorder(TreeNode *root, int& preSum) {
    if (!root)
      return;
    reInorder(root->right, preSum);
    root->val += preSum;
    preSum = root->val;
    reInorder(root->left, preSum);
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
  TreeNode *res = s.convertBST(vec[0]);
  for (TreeNode *t : vec) {
    cout << t->val << " ";
    delete t;
  }
  cout << endl;
  vec.clear();
  return 0;
}
