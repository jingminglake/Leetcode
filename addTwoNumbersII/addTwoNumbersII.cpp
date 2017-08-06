#include <iostream>
#include <cstddef>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    ListNode *p1 = l1, *p2 = l2;
    while (p1) {
      s1.push(p1->val);
      p1 = p1->next;
    }
    while (p2) {
      s2.push(p2->val);
      p2 = p2->next;
    }
    ListNode dummy(0);
    int carry = 0;
    while (!s1.empty() || !s2.empty()) {
      int sum = 0;
      if (!s1.empty()) {
	sum += s1.top();
	s1.pop();
      }
      if (!s2.empty()) {
	sum += s2.top();
	s2.pop();
      }
      sum += carry;
      carry = sum / 10;
      ListNode *l = new ListNode(sum % 10);
      l->next = dummy.next;
      dummy.next = l;  
    }
    if (carry == 1) {
      ListNode *l = new ListNode(1);
      l->next = dummy.next;
      dummy.next = l;
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
  int a1[3] = {5, 6, 4};
  ListNode *l1 = new ListNode(a1[0]);
  ListNode *tail1 = l1;
  for (int i = 1; i < sizeof(a1)/sizeof(a1[0]); i++) {
    ListNode *temp = new ListNode(a1[i]);
    tail1->next = temp;
    tail1 = temp;
  }
  Solution s;
  ListNode *h = s.addTwoNumbers(l, l1);
  while (l) {
    ListNode *p = l;
    l = l->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  while (l1) {
    ListNode *p = l1;
    l1 = l1->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  return 0;
}
