#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
    ListNode(int x, ListNode *_next): val(x), next(_next){}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *last = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            int sum = l1_val + l2_val + carry;
            ListNode *n = new ListNode(sum % 10);
            carry = sum / 10;
            last->next = n;
            last = last->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return dummy.next;
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
