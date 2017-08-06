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
  ListNode* insertionSortList(ListNode* head) {
    if (!head)
      return head;
    ListNode dummy(INT_MIN);
    ListNode *cur = head;
    while (cur) {
      ListNode *temp = cur->next;
      ListNode *prev = &dummy;
      while (prev->next && prev->next->val < cur->val) {
        prev = prev->next;
      }
      cur->next = prev->next;
      prev->next = cur;
      cur = temp;
    }
    return dummy.next;
  }
};

int main()
{
  int a[4] = {7, 2, 4, 3};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  ListNode *h = s.insertionSortList(l);
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  return 0;
}
