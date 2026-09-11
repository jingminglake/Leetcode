#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  bool findTarget(TreeNode* root, int k) {
    if (!root)
      return false;
    unordered_set<int> s;
    return findTargetHelper(root, k, s);
  }
  bool findTargetHelper(TreeNode* root, int k, unordered_set<int>& s) {
    if (!root)
      return false;
    if (s.count(k - root->val))
      return true;
    s.insert(root->val);
    return findTargetHelper(root->left, k, s) || findTargetHelper(root->right, k, s);
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
  cout << s.findTarget(vec[0], 28) << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
