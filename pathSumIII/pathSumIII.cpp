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
  int pathSum(TreeNode *root, int sum) {
    if (!root)
      return 0;
    return pathSum(root->left, sum) + pathSum(root->right, sum)  + path(root, sum);
  }
  int path(TreeNode *root, int sum) {
     if (!root)
      return 0;
     int remain = sum - root->val;
     if (remain == 0) {
       //cout << "path-->" << root->val << endl;
       return path(root->left, remain) + path(root->right, remain) + 1;
      } else {
        return path(root->left, remain) + path(root->right, remain);
      }
  }
};

int main()
{
  Solution s;
  int tree[8] = {1,-2,-3,1,3,-2,9999,-1};
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
  cout << s.pathSum(vec[0], -2) << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
