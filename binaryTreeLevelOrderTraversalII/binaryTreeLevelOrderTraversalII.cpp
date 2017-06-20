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
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > ans;
    if (!root)
      return ans;
    queue<TreeNode *> q;
    q.push(root);
    vector<int> vec;
    while (!q.empty()) {
      int levelNum = q.size();
      TreeNode *temp;
      for (int i = 0; i < levelNum; i++) {
	temp = q.front();
	if (temp->left)
	  q.push(temp->left);
	if (temp->right)
	  q.push(temp->right);
      	vec.push_back(temp->val);
	q.pop();
      }
      ans.push_back(vec);
      vec.clear();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution s;
  int tree[7] = {1,2,3,4,9999,9999,5};
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
  vector<vector<int> > levels = s.levelOrderBottom(vec[0]);
  for (vector<int>& level : levels) {
    for (int i : level)
      cout << i << " ";
    cout << endl;
  }
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
