#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        while (head) {
            while (head->next && head->val == head->next->val) {
                ListNode *n = head;
                head = head->next;
                delete n;
            }
            if (prev->next == head) {
                prev = prev->next;
            } else {
                prev->next = head->next;
                delete head;
            }
            head = prev->next;
        }
        return dummy.next;
    }
};

int main()
{
    int a[7] = {1, 2, 3, 3, 4, 4, 5};
    ListNode *l = new ListNode(a[0]);
    ListNode *tail = l;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = temp;
    }
    Solution s;
    ListNode * h = s.deleteDuplicates(l);
    while (h) {
        ListNode *p = h;
        h = h->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;

    return 0;
}
