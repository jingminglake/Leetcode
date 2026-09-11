#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> s;
        ListNode *cur = head;
        while (cur) {
            s.push(cur);
            cur = cur->next;
        }
        int carry = 1;
        while (!s.empty() && carry) {
            ListNode *temp = s.top();
            s.pop();
            int sum = temp->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;
        }
        if (carry) {
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};

int main()
{
  int a[5] = {1, 2, 5, 8, 1};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  s.plusOne(l);
  ListNode * h = l;
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;

  return 0;
}
