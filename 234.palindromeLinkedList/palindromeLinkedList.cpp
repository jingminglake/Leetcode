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
  bool isPalindrome(ListNode* head) {
    if(!head || !head->next)
      return true;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    while (slow) {
      if (head->val != slow->val)
	return false;
      head = head->next;
      slow = slow->next;
    }
    return true;
  }
  ListNode * reverse(ListNode *head) {
    ListNode *newHead = NULL; 
    while (head) {
      ListNode* p = head->next;
      head->next = newHead;
      newHead = head;
      head = p;
    }
    return newHead;
  }
};

int main()
{
  int a[5] = {4, 3, 2, 3, 4};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  Solution s;
  cout << s.isPalindrome(l) << endl;
  ListNode *h = l;
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;
  return 0;
}
