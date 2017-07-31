#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator{
public:
  BSTIterator(TreeNode *root) {
    storePath(root);
  }
  /** @return whether we have a next smallest number */
  bool hasNext(){
    return !s.empty();
  }
  /** @return the next smallest number */
  int next() {
    TreeNode *temp = s.top();
    s.pop();
    storePath(temp->right);
    return temp->val;
  }
  void storePath(TreeNode *t) {
    while (t) {
      s.push(t);
      t = t->left;
    }
  }
  stack<TreeNode *> s;
};

int main()
{
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
  BSTIterator i = BSTIterator(vec[0]);
  while (i.hasNext())
    cout << i.next() << " ";
  cout << endl;
  vec.clear();
  return 0;
}
