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
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
      return head;
    ListNode dummy(INT_MIN);
    dummy.next = head;
    ListNode *slow = &dummy, *fast = &dummy;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *head2 = slow->next;
    slow->next = NULL;
    ListNode* head1 = sortList(head);
    head2 = sortList(head2);
    ListNode *tail = &dummy;
    while (head1 && head2) {
      if (head1->val < head2->val) {
	tail->next = head1;
	tail = head1;
	head1 = head1->next;
      } else {
	tail->next = head2;
	tail = head2;
	head2 = head2->next;
      }
    }
    if (head1) {
      tail->next = head1;
    }
    if (head2) {
      tail->next = head2;
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
  ListNode *h = s.sortList(l);
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  return 0;
}
