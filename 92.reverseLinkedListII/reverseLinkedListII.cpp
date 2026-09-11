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
    if (m > n || m <= 0 || n <= 0 || !head)
      return NULL;
    ListNode dummy(0);
    dummy.next = head;
    ListNode *newHead = &dummy;
    ListNode *nodeMPrev = newHead;
    ListNode *nodeN = newHead;
    for (int i = 0; i < n; i++) {
      if (!nodeN)
	return NULL;
      if (i == m - 1)
	nodeMPrev = nodeN;
      nodeN = nodeN->next;
    }
    if (!nodeN)
      return NULL;
    ListNode *nodeM = nodeMPrev->next; 
    ListNode *nodeNPlus = nodeN->next;
    ListNode *prev = NULL;
    ListNode *cur = nodeMPrev;
    while (cur != nodeNPlus) {
      ListNode *temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
    }
    nodeM->next = nodeNPlus;
    nodeMPrev->next = nodeN;
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
