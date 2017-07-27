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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    if (!root)
      return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      TreeNode *mostRight = NULL;
      for (int i = 0; i < size; i++) {
	mostRight = q.front();
	q.pop();
	if (mostRight->left)
	  q.push(mostRight->left);
	if (mostRight->right)
	  q.push(mostRight->right);
      }
      if (mostRight)
	ans.push_back(mostRight->val);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int tree[7] = {1,2,3,9999,5,9999,4};
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
  vector<int> res = s.rightSideView(vec[0]);
  for (int i : res) {
    cout << i << " ";
  }
  cout << endl;
  for (TreeNode *t : vec) {
    //cout << t->val << " ";
    delete t;
  }
  vec.clear();
  return 0;
}
