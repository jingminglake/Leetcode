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
    TreeLinkNode *head = root;// first node in lower level
    TreeLinkNode *prev = NULL; // previous node in lower level
    TreeLinkNode *cur = NULL;// node in the "queue", upper level
    while (head) {
      cur = head;
      prev = NULL;
      head = NULL;
      while (cur) {
	if (cur->left) {
	  if (prev)
	    prev->next = cur->left;
	  else
	    head = cur->left;
	  prev = cur->left;
	}
	if (cur->right) {
	  if (prev)
	    prev->next = cur->right;
	  else
	    head = cur->right;
	  prev = cur->right;
	}
	cur = cur->next;
      }
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
  int tree[7] = {1,2,3,4,5,9999,7};
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
    TreeLinkNode *temp;
    while (t) {
      q.push(t);
      temp = t;
      t = t->left;
    }
    t = temp->right;
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
