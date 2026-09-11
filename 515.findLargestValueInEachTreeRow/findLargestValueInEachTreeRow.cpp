#include <iostream>
#include <vector>
#include <queue>
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
  vector<int> largestValues(TreeNode *root) {
    vector<int> ans;
    if (!root)
      return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *temp;
      long largestV = LONG_MIN;
      int size = q.size();
      for (int i = 0; i < size; i++) {
	temp = q.front();
	q.pop();
	largestV = max(largestV, long(temp->val));
	if (temp->left)
	  q.push(temp->left);
	if (temp->right)
	  q.push(temp->right);
      }
      if (largestV != LONG_MIN) {
	ans.push_back(largestV);
      }
    }
    return ans;
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
  vector<int> res = s.largestValues(vec[0]);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  for (TreeNode *t : vec) {
    //cout << t->val << " ";
    delete t;
  }
  vec.clear();
  return 0;
}
