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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1)
      return l2;
    else if (!l2)
      return l1;
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while (l1 && l2) {
      if (l1 && l2 && l1->val <= l2->val) {
	tail->next = l1;
	tail = l1;
	l1 = l1->next;
      } else if (l1 && l2 && l1->val > l2->val) {
	tail->next = l2;
	tail = l2;
	l2 = l2->next;
      } else if (!l1 && l2) {
	tail->next = l2;
	tail = l2;
	l2 = l2->next;
      } else if (l1 && !l2) {
	tail->next = l1;
	tail = l1;
	l1 = l1->next;
      } 
    }//while
    tail->next = l1 ? l1 : l2;
    ListNode *ans = dummy->next;
    delete dummy;
    return ans;
  }
};

int main()
{
  int a[5] = {1, 2, 5, 8, 10};
  int b[5] = {3, 4, 6, 7, 9};
  ListNode *l1 = new ListNode(a[0]);
  ListNode *tail1 = l1;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp1 = new ListNode(a[i]);
    tail1->next = temp1;
    tail1 = temp1;
  }
  ListNode *l2 = new ListNode(b[0]);
  ListNode *tail2 = l2;
  for (int j = 1; j < sizeof(b)/sizeof(b[0]); j++) {
    ListNode *temp2 = new ListNode(b[j]);
    tail2->next = temp2;
    tail2 = temp2;
  }
  
  Solution s;
  ListNode *h = s.mergeTwoLists(l1, l2);
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;

  return 0;
}
