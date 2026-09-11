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
  ListNode* reorderRight(ListNode* head, int k) {
    if (!head || k == 0)
      return head;
    ListNode dummy(0);
    dummy.next = head;
    int size = 0;
    ListNode *p = head;
    while (p) {
      size++;
      p = p->next;
    }
    if (k % size == 0)
      return head;
    int step = size - k % size;
    p = &dummy;
    int i = 0;
    while (i < step) {
      p = p->next;
      i++;
    }
    ListNode *q = p;
    dummy.next = p->next;
    while (p->next) {
      p = p->next;
    }
    p->next = head;
    q->next = NULL;
    return dummy.next;
  }
};

int main()
{
  int a[1] = {1};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  ListNode *h = s.reorderRight(l, 1);
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  return 0;
}
