#include <iostream>
#include <cstddef>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {
  }
};

class Solution{
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head)
      return head;
    ListNode *pHead = new ListNode(0);
    pHead->next = head;
    ListNode *p = pHead, *q = pHead;
    for (int i = 0; i < n; i++)
      q = q->next;
    while (q->next) {
      p = p->next;
      q = q->next;
    }
    cout << "p: " << p->val << endl;
    q = p->next;
    p->next = q->next;
    delete q;
    head = pHead->next;
    delete pHead;
    return head;
  }
};

int main()
{
  int a[5] = {1, 2, 3, 4, 5};
  ListNode *head = new ListNode(a[0]);
  ListNode *tail = head;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  s.removeNthFromEnd(head, 2);
  while (head != NULL) {
    ListNode *p = head;
    head = head->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  return 0;
}
