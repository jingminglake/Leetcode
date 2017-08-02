#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  int rob(TreeNode *root) {
    unordered_map<TreeNode*, int> m;
    //return robHelper(root, m);
    vector<int> res = robHelperII(root);
    return max(res[0], res[1]);
  }
  int robHelper(TreeNode *root, unordered_map<TreeNode*, int>& m) {
    if (!root)
      return 0;
    unordered_map<TreeNode*, int>::iterator it = m.find(root);
    if (it != m.end())
      return it->second; 
    int grandChildrenLeft = 0, grandChildrenRight = 0;
    if (root->left) {
      grandChildrenLeft = robHelper(root->left->left, m) + robHelper(root->left->right, m);
    }
    if (root->right) {
      grandChildrenRight = robHelper(root->right->left, m) + robHelper(root->right->right, m);
    }
    int res = max(grandChildrenLeft + grandChildrenRight + root->val, robHelper(root->left, m) + robHelper(root->right, m));
    m.insert(make_pair<TreeNode*, int>((TreeNode*)root, (int)res));
    return res;
  }
  vector<int> robHelperII(TreeNode *root) {
    vector<int> res(2,0);
    if (!root)
      return res;
    vector<int> resLeft = robHelperII(root->left);
    vector<int> resRight = robHelperII(root->right);
    res[0] = max(resLeft[0], resLeft[1]) + max(resRight[0], resRight[1]);//0: not choose, 1:choose
    res[1] = root->val + resLeft[0] + resRight[0];
    return res;
  }
};

int main()
{
  int tree[7] = {3,2,3,9999,3,9999,1};
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
  Solution s;
  cout << s.rob(vec[0]) << endl;
  for (TreeNode * tn : vec) {
    delete tn;
  }
  vec.clear();
  return 0;
}
