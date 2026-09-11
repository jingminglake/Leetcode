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
  vector<double> avergeOfLevels(TreeNode *root) {
    vector<double> ans;
    if (!root)
      return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      double levelNodesSum = 0;
      int levelNodesNum = q.size();
      for (int i = 0; i < levelNodesNum; i++) {
	TreeNode *temp = q.front();
	q.pop();
	levelNodesSum += temp->val;
	if (temp->left)
	  q.push(temp->left);
	if (temp->right)
	  q.push(temp->right);
      }
      ans.push_back(levelNodesSum / levelNodesNum);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int tree[7] = {3,9,20,9999,9999,15,7};
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
  vector<double> res = s.avergeOfLevels(vec[0]);
  for (double v : res)
    cout << v << " ";
  cout << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
