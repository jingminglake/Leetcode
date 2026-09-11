#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        while (prev) {
            ListNode* cur = prev->next;
            if (cur && cur->val == val) {
                prev->next = cur->next;
                delete cur;
            } else {
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};

int main()
{
    int a[5] = {3, 1, 2, 3, 3};
    ListNode *l = new ListNode(a[0]);
    ListNode *tail = l;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = temp;
    }
    Solution s;
    ListNode * h = s.removeElements(l, 3);;
    while (h) {
        ListNode *p = h;
        h = h->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;

    return 0;
}
