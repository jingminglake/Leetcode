#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) {
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return p1;
    }
};

int main()
{
    int a[5] = {4, 3, 2, 3, 4};
    int b[3] = {1, 2, 3};
    ListNode *l = new ListNode(a[0]);
    ListNode *tail = l;
    ListNode *t = NULL;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = temp;
        if (i == 1)
            t = temp;
    }
    ListNode *l2 = new ListNode(b[0]);
    ListNode *tail2 = l2;
    for (int i = 1; i < sizeof(b)/sizeof(b[0]); i++) {
        ListNode *temp = new ListNode(b[i]);
        tail2->next = temp;
        tail2 = temp;
    }
    tail2->next = t;
    Solution s;
    cout << s.getIntersectionNode(l, l2)->val << endl;


    tail2->next = NULL;
    ListNode *h = l;
    while (h) {
        ListNode *p = h;
        h = h->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;
    ListNode *h2 = l2;
    while (h2) {
        ListNode *p = h2;
        h2 = h2->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;
    return 0;
}
