#include<iostream>
#include<string>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL){}
  ListNode(int x, ListNode *_next): val(x), next(_next){}
};

class Solution
{
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    ListNode *p1 = l1, *p2 = l2;
    ListNode l3(0);
    ListNode *tail = &l3;
    int carry = 0;
    while (p1 != NULL || p2 != NULL)
    {
      int x = (p1 != NULL) ? p1->val : 0;
      int y = (p2 != NULL) ? p2->val : 0;
      int sum = x + y + carry;
      if(sum  >= 10)
      {
	tail->next = new ListNode(sum % 10);
	tail = tail->next;
	carry = 1;
      }
      else
      {
	tail->next = new ListNode(sum);
	tail = tail->next;
	carry = 0;
      }
      if (p1 != NULL)
        p1 = p1->next;
      if (p2 != NULL)
        p2 = p2->next;
    }
    if(carry == 1)
    {
      tail->next = new ListNode(1);
      tail = tail->next;
    }
    return l3.next;
  }
};

int main(void)
{
  ListNode *head1 = NULL;
  ListNode *head2 = NULL;
  int s;
  while (cin >> s && s != -1)
  {
    head1 = new ListNode(s, head1);
    // cout << "s-->" << s << " ";
  }
  s = 0;
  while (cin >> s && s != -1)
  {
    head2 = new ListNode(s, head2);
    // cout << "s2-->" << s << " ";
  }

  Solution sol;
  ListNode *head3 = sol.addTwoNumbers(head1, head2);
  /* ListNode *p = head1;
  while (p != NULL)
  {
    cout << p->val << " ";
    p = p->next; 
  }
  cout << endl;
  p = head2;
  while (p != NULL)
  {
    cout << p->val << " ";
    p = p->next; 
  }
  cout << endl;*/

  ListNode *p = head3;
  while (p != NULL)
  {
    cout << p->val << " ";
    p = p->next; 
  }
  cout << endl;
  
  ListNode *toFree;
  while(head1 != NULL)
  {
    toFree = head1;
    head1 = head1->next;
    delete head1;
  }
  while(head2 != NULL)
  {
    toFree = head2;
    head2 = head2->next;
    delete head2;
  }
  while(head3 != NULL)
  {
    toFree = head3;
    head3 = head3->next;
    delete head3;
  }
  return 0;
}
