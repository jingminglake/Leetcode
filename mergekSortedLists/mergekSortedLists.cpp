#include <iostream>
#include <cstddef>
#include <queue>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Compare {
public:
  bool operator()(const ListNode* l, const ListNode* r) {
    return l->val > r->val;
  }
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int size = lists.size();
    if (size == 0)
      return NULL;
    ListNode dummy(INT_MIN);
    ListNode *tail = &dummy;

    priority_queue<ListNode*, vector<ListNode*>, Compare> q;
    
    for (ListNode* head : lists)
      if (head)
	q.push(head);
    while (!q.empty()) {
      tail->next = q.top();
      q.pop();
      tail = tail->next;
      if (tail->next)
	q.push(tail->next);
    }
    return dummy.next;
  }
};

int main()
{
  int a[4] = {2, 3, 4, 7};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  ListNode *l1 = new ListNode(a[0]);
  ListNode *tail1 = l1;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail1->next = temp;
    tail1 = temp;
  }
  ListNode *l2 = new ListNode(a[0]);
  ListNode *tail2 = l2;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail2->next = temp;
    tail2 = temp;
  }
  vector<ListNode*> vec;
  vec.push_back(l);
  vec.push_back(l1);
  vec.push_back(l2);
  Solution s;
  ListNode *h = s.mergeKLists(vec);
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  return 0;
}
