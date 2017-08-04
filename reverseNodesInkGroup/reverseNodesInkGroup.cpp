#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *newHead = &dummy;
    while (newHead) {
      newHead = reverseKNodes(newHead, k);
    }
    return dummy.next;
  }
  ListNode* reverseKNodes(ListNode* prev, int k) {
    if (!prev)
      return NULL;
    if (k <= 0)
      return NULL;
    ListNode* nodeK = prev;
    for (int i = 0; i < k; i++) {
      if (!nodeK)
	return NULL;
      nodeK = nodeK->next;
    }
    if (!nodeK)
      return NULL;
    ListNode *node1 = prev->next;
    ListNode *nodeKplusOne = nodeK->next;
    ListNode *pre = NULL;
    ListNode *cur = prev;
    while (cur != nodeKplusOne) {
      ListNode *temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    prev->next = nodeK;
    node1->next = nodeKplusOne;
    return node1;
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
  ListNode* res = s.reverseKGroup(l, 3);
  while (res) {
      cout << res->val << " ";
    res = res->next;
  }
  cout << endl;
  return 0;
}
