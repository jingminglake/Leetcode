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
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode *cur = root;
    while (cur && cur->val <= p->val) {
      cur = cur->right;
    }
    if (!cur)
      return cur;
    TreeNode *left = inorderSuccessor(cur->left, p);
    return (left && left->val > p->val) ? left : cur;
  }
};

int main()
{
  Solution s;
  int tree[12] = {3,2,6,1,9999,5,7,9999,9999,9999,9999,4};
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
  cout << s.inorderSuccessor(vec[0], vec[2])->val;
  cout << endl;
  for (TreeNode *t : vec) {
    //cout << t->val << " ";
    delete t;
  }
  vec.clear();
  return 0;
}
