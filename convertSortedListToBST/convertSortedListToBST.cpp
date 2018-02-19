#include <iostream>
#include <cstddef>
#include <queue>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head)
      return nullptr;
    return sortedListToBSTHelper(head, nullptr);
  }
  TreeNode *sortedListToBSTHelper(ListNode* head, ListNode* last) {
    if (!head || head == last)
      return nullptr;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != last && fast->next != last) {
      slow = slow->next;
      fast = fast->next->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    root->left = sortedListToBSTHelper(head, slow);
    root->right = sortedListToBSTHelper(slow->next, last);
    return root;
  }
  void preorder(TreeNode *root) {
    if (!root)
      return;
    TreeNode *leftChild = root->left;
    TreeNode *rightChild = root->right;
    cout << root->val << " ";
    delete root;
    preorder(leftChild);
    preorder(rightChild);
  }
};

int main()
{
  int a[2] = {1, 3};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  TreeNode *h = s.sortedListToBST(l);
  s.preorder(h);
  while (l) {
    ListNode *p = l;
    l = l->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  return 0;
}
