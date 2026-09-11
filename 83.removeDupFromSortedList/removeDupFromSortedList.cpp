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
    int prev = head->val;
    ListNode *p = head;
    while (p->next) {
      cout << p->val << "---" << endl;
      if (p->next->val == prev) {
	ListNode* q = p->next;
	p->next = q->next;
	delete q;
      } else {
	prev = p->next->val;
	p = p->next;
      }
    }
    return head;
  }
};

int main()
{
  int a[5] = {1, 1, 2, 3, 3};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  ListNode * h = s.deleteDuplicates(l);;
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;

  return 0;
}
