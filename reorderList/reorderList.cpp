#include <iostream>
#include <cstddef>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void reorderList(ListNode* head) {
    if (!head)
      return;
    // find middle node 
    ListNode *low = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      low = low->next;
      fast = fast->next->next;
    }
    ListNode *middleNode = low->next;
    cout << middleNode->val << endl;
    // reverse second half
    ListNode *prev = NULL;
    ListNode *cur = middleNode;
    while (cur) {
      ListNode *temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
    }
    low->next = NULL; 
    // merge
    ListNode *h1 = head;
    ListNode *h2 = prev;
    while (h2) {
      ListNode *temp = h2->next;
      h2->next = h1->next;
      h1->next = h2;
      h1 = h2->next;
      h2 = temp;
    }
  }
};

int main()
{
  int a[5] = {1, 2, 3, 4, 5};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  s.reorderList(l);
  ListNode *h = l;
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  return 0;
}
