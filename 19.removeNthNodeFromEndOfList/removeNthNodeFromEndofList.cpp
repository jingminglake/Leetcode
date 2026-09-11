#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p1 = head;
        while (n) {
            p1 = p1->next;
            n--;
        }
        ListNode* p2 = &dummy;
        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* to_delete = p2->next;
        p2->next = p2->next->next;
        delete to_delete;
        return dummy.next;
    }
};

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(a[0]);
    ListNode *tail = head;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = temp;
    }
    Solution s;
    s.removeNthFromEnd(head, 2);
    while (head != NULL) {
        ListNode *p = head;
        head = head->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;
    return 0;
}
