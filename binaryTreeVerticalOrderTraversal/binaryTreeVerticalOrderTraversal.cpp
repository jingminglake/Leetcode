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
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int> > res;
    if (!root)
      return res;
    int minV = INT_MAX, maxV = INT_MIN;
    findResLength(root, minV, maxV, 0);
    res.resize(maxV - minV + 1);
    queue<pair<TreeNode*, int> > q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
	int resSize = res.size();
	pair<TreeNode*, int> temp = q.front();
	q.pop();
	res[temp.second - minV].push_back(temp.first->val);
	if (temp.first->left)
	  q.push(make_pair(temp.first->left, temp.second - 1));
	if (temp.first->right)
	  q.push(make_pair(temp.first->right, temp.second + 1));
      }
    }
    return res;
  }
  void findResLength(TreeNode* root, int& minV, int& maxV, int level) {
    if (!root)
      return;
    minV = min (minV, level);
    maxV = max (maxV, level);
    findResLength (root->left, minV, maxV, level - 1);
    findResLength (root->right, minV, maxV, level + 1);
  }
};

int main()
{
  Solution s;
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
  for(vector<int>& v : s.verticalOrder(vec[0])) {
    for (int i : v)
      cout << i << " ";
    cout << endl;
  }
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
