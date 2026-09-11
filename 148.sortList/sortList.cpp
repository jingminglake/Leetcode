#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* slow = head, *fast = head;
        ListNode* mid = head;
        while (fast && fast->next) {
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        mid->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergeSortedList(l1, l2);
    }
    ListNode* mergeSortedList(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode dummy(0);
        ListNode* last = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                last->next = l1;
                last = last->next;
                l1 = l1->next;
            } else {
                last->next = l2;
                last = last->next;
                l2 = l2->next;
            }
        }
        if (l1) {
            last->next = l1;
        }
        if (l2) {
            last->next = l2;
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
    Solution s;
    ListNode *h = s.sortList(l);
    while (h) {
        ListNode *p = h;
        h = h->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;
    return 0;
}
