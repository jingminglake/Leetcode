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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head)
      return head;
    ListNode dummy(0);
    dummy.next = head;
    ListNode *newHead = &dummy;
    ListNode *prev = newHead;
    ListNode *cur = newHead->next;
    bool isDup = false;
    while (cur) {
      ListNode *temp = cur->next;
      if (!temp)
	break;
      while (temp && temp->val == cur->val) {
	isDup = true;
	temp = temp->next;
      }
      if (isDup) {
	ListNode *ln = prev->next;
	while (ln != temp) {
	  ListNode *q = ln;
	  ln = ln->next;
	  delete q;
	}
	prev->next = temp;
	cur = temp;
	isDup = false;
      } else {
	prev = cur;
	cur = temp;
      }
    }
    return dummy.next;
  }
};

int main()
{
  int a[7] = {1, 2, 3, 3, 4, 4, 5};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  ListNode * h = s.deleteDuplicates(l);
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;

  return 0;
}
