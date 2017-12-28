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
  int longestUnivaluePath(TreeNode *root) {
    int res = 0;
    if (root)
      dfs(root, res);
    return res;
  }
  int dfs(TreeNode* node, int& res) {
    if (!node)
      return 0;
    int left = dfs(node->left, res);
    int right = dfs(node->right, res);
    int l = 0, r = 0;
    if (node->left && node->left->val == node->val)
      l = left + 1;
    if (node->right && node->right->val == node->val)
      r = right + 1;
    res = max(res, l + r);
    return max(l, r);
  }
};

int main()
{
  Solution s;
  int tree[7] = {5,4,5,1,1,9999,5};
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
  cout << s.longestUnivaluePath(vec[0]) << endl;
  
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
