#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return head;
        ListNode *odd = head, *even = head->next;
        ListNode *even_head = head->next; 
        while (even && even->next) {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
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
    ListNode * h = s.oddEvenList(l);
    while (h) {
        ListNode *p = h;
        h = h->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;

    return 0;
}
