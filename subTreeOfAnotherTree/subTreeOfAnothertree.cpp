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
  bool isSubtree(TreeNode *s, TreeNode* t) {
    /*queue<TreeNode*> q;
    q.push(s);
    while (!q.empty()) {
      TreeNode *temp = q.front();
      q.pop();
      if (temp && temp->val == t->val) {
	if (compare(temp, t))
	    return true;
      }
      if (temp->left)
	q.push(temp->left);
      if (temp->right)
	q.push(temp->right);
    }
    return false;*/
    if (!s)
      return false;
    if (compare(s, t))
      return true;
    else
      return isSubtree(s->left, t) || isSubtree(s->right, t);
  }
  bool compare(TreeNode *s, TreeNode* t) {
    if (!s && !t)
      return true;
    else if (s && t)
      return (s->val == t->val) && compare(s->left, t->left) && compare(s->right, t->right);
    else
      return false;
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
