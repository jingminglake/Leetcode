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
  int widthOfBinaryTree(TreeNode* root) {
    int res = 0;
    if (!root)
      return 0;
    queue<pair<TreeNode*, int> > q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
      int size = q.size();
      int left = q.front().second;
      for (int i = 0; i < size; i++) {
	auto& temp = q.front();
	q.pop();
	int right = temp.second;
	if (temp.first->left) {
	  q.push(make_pair(temp.first->left, right * 2));
	}
	if (temp.first->right) {
	  q.push(make_pair(temp.first->right, right * 2 + 1));
	}
	res = max (res, right - left + 1);
      }
    }
    return res;
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
  cout <<  s.widthOfBinaryTree(vec[0]);
  cout << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
