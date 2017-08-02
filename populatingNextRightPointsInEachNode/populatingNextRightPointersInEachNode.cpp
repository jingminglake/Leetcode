#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution{
public:
  void connect(TreeLinkNode *root) {
    if (!root)
      return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while (pre->left) {
      cur = pre;
      while (cur) {
	cur->left->next = cur->right;
	if (cur->next)
	  cur->right->next = cur->next->left;
	cur = cur->next;
      }
      pre = pre->left;
    }
  }
  void preorder(TreeLinkNode* root) {
    if (!root)
      return;
    cout << root->val << " ";
    TreeLinkNode *leftChild = root->left;
    TreeLinkNode *rightChild = root->right;
    delete root;
    preorder(leftChild);
    preorder(rightChild);
  }
};

int main()
{
  int tree[7] = {1,2,3,4,5,6,7};
  int size = sizeof(tree)/sizeof(tree[0]);
  vector<TreeLinkNode *> vec;
  for (int i = 0; i < size; i++) {
    if (tree[i] != 9999) {
      vec.push_back(new TreeLinkNode(tree[i]));
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
  Solution s;
  s.connect(vec[0]);
  queue<TreeLinkNode*> q;
  TreeLinkNode *t = vec[0];
  while (t) {
    q.push(t);
    t = t->left;
  }
  while (!q.empty()) {
    TreeLinkNode *first = q.front();
    q.pop();
    while (first) {
      cout << first->val << " ";
      first = first->next;
    }
    cout << endl;
  }
  for (TreeLinkNode * tn : vec) {
    delete tn;
  }
  vec.clear();
  return 0;
}
