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
  ListNode* partition(ListNode* head, int x) {
    ListNode dummy0(INT_MIN), dummy1(INT_MIN);
    ListNode *lessP = &dummy0;
    ListNode *greaterP = &dummy1;
    ListNode* cur = head;
    while (cur) {
      if (cur->val < x) {
	lessP = lessP->next = cur;
      } else {
        greaterP = greaterP->next = cur;
      }
      cur = cur->next;
    }
    greaterP->next = NULL;
    lessP->next = dummy1.next;
    return dummy0.next;
  }
};

int main()
{
  int a[6] = {1, 4, 3, 2, 5, 2};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  ListNode * h = s.partition(l, 3);
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  return 0;
}
