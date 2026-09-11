#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head || !head->next)
      return head;
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;
    ListNode *cur = head;
    for (int i = 0; i < m - 1; i++) {
      pre = cur;
      cur = cur->next;
    }
    ListNode *nex = nullptr;
    for (int i = 0; i < n - m; i++) {
      nex = cur->next;
      cur->next = nex->next;
      nex->next = pre->next;
      pre->next = nex;
    }
    return dummy.next;
  }
};

int main()
{
  int a[5] = {1, 2, 3, 4, 5};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  ListNode* res = s.reverseBetween(l, 2, 4);
  while (res) {
    cout << res->val << " ";
    res = res->next;
  }
  cout << endl;
  return 0;
}
