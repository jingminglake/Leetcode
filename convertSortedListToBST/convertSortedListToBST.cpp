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
      return NULL;
    return sortedListToBSTHelper(head, NULL);
  }
  TreeNode* sortedListToBSTHelper(ListNode* head, ListNode* tail) {
     if (head == tail)
      return NULL;
     if (head->next == tail)
      return new TreeNode(head->val);
    ListNode dummy(0);
    dummy.next = head;
    ListNode *slow = &dummy;
    ListNode *fast = &dummy;
    while (fast != tail && fast->next != tail) {
      slow = slow->next;
      fast = fast->next->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    TreeNode *leftChild = sortedListToBSTHelper(dummy.next, slow);
    TreeNode *rightChild = sortedListToBSTHelper(slow->next, tail);
    root->left = leftChild;
    root->right = rightChild;
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
