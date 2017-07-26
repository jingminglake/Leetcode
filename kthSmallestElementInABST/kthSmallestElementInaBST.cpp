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
  int kthSmallest(TreeNode *root, int k) {
    return find(root, k);
  }
  int find(TreeNode *root, int k) {
    if (!root)
      return 0;
    int rk = rank(root);
    if (rk == k)
      return root->val;
    else if (rk < k)
      return find (root->right, k - rk);
    else if (rk > k)
      return find (root->left, k);
  }
  int rank(TreeNode *root) {
    if (!root)
      return 0;
    return count(root->left) + 1;
  }
  int count(TreeNode *root) {
    if (!root)
      return 0;
    return count(root->left) + count(root->right) + 1;
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
  cout << s.kthSmallest(vec[0], 3);
  for (TreeNode *t : vec) {
    //cout << t->val << " ";
    delete t;
  }
  cout << endl;
  vec.clear();
  return 0;
}
