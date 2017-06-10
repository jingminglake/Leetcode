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
  ListNode* reverseList(ListNode* head) {
    /*ListNode *newHead = NULL; 
    while (head) {
      ListNode* p = head->next;
      head->next = newHead;
      newHead = head;
      head = p;
    }
    return newHead;*/
    return reverse(head, NULL);
  }
  ListNode * reverse(ListNode *head, ListNode *newHead) {
    if (!head)
      return newHead;
    ListNode* p = head->next;
    head->next = newHead;
    return reverse(p, head);
  }
};

int main()
{
  int a[5] = {0, 1, 2, 3, 4};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  ListNode * h = s.reverseList(l);
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;

  return 0;
}
