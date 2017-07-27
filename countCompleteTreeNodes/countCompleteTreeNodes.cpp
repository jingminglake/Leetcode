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
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;
    int h = height(root);
    if (h == 1)
      return 1;
    int hRight = height(root->right);
    if (h - 1 == hRight) {
      return countNodes(root->right) + (1 << hRight);
    } else if (h - 2 == hRight) {
      return countNodes(root->left) + (1 << hRight);
    } else
      cout << "impossible~~~" << endl;
  }
  int height(TreeNode *root) {
    if (!root)
      return 0;
    return 1 + height(root->left);
  }
};

int main()
{
  Solution s;
  int tree[9] = {5,2,13,1,2,3,4,5,6};
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
  cout << s.countNodes(vec[0]);
  for (TreeNode *t : vec) {
    //cout << t->val << " ";
    delete t;
  }
  cout << endl;
  vec.clear();
  return 0;
}
