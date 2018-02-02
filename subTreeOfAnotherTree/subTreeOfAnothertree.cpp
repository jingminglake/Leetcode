#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!t || !s)
      return false;
    if (check(s, t))
      return true;
    else
      return isSubtree(s->left, t) || isSubtree(s->right, t);
  }
  bool check(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2)
      return true;
    if (!t1 || !t2)
      return false;
    if (t1->val != t2->val)
      return false;
    return check(t1->left, t2->left) && check(t1->right, t2->right);
  }
};

int main()
{
  Solution s;
  int tree[5] = {3,4,5,1,2};
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
  int tree2[3] = {4,1,2};
  int size2 = sizeof(tree2)/sizeof(tree2[0]);
  vector<TreeNode *> vec2;
  for (int i = 0; i < size2; i++) {
    if (tree2[i] != 9999) {
      vec2.push_back(new TreeNode(tree2[i]));
    } else {
      vec2.push_back(NULL);
    }
  }
  for (int i = 0; i < size/2; i++) {
    if(!vec2[i])
      continue;
    if (i*2 + 1 < size)
      vec2[i]->left = vec2[i*2 + 1];
    if (i*2 + 2 < size)
      vec2[i]->right = vec2[i*2 + 2];
  }
  cout << s.isSubtree(vec[0], vec2[0]) << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  for (TreeNode *t : vec2) {
    delete t;
  }
  vec.clear();
  vec2.clear();
  return 0;
}
