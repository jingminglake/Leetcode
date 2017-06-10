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
  ListNode* removeElements(ListNode* head, int val) {
    if (!head)
      return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p = dummy;
    while (p->next) {
      cout << p->next->val << "---" << endl;
      if (p->next->val == val) {
	ListNode* q = p->next;
	p->next = q->next;
	delete q;
      } else {
	p = p->next;
      }
    }
    head = dummy->next;
    delete dummy;
    return head;
  }
};

int main()
{
  int a[5] = {3, 1, 2, 3, 3};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  ListNode * h = s.removeElements(l, 3);;
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;

  return 0;
}
