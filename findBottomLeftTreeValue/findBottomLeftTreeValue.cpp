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
  int findBottomLeftValue(TreeNode *root) {
    if (!root)
      return -1;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
	root = q.front();
	q.pop();
	if (root->right)
	  q.push(root->right);
	if (root->left)
	  q.push(root->left);
      }
    }
    return root->val;
  }
};

int main()
{
  Solution s;
  int tree[12] = {1,2,3,4,9999,5,6,9999,9999,9999,9999,7};
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
  cout << s.findBottomLeftValue(vec[0]);
  cout << endl;
  for (TreeNode *t : vec) {
    //cout << t->val << " ";
    delete t;
  }
  vec.clear();
  return 0;
}
