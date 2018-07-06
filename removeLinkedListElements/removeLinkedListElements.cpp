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
        ListNode *cur = &dummy;
        while (cur) {
            if (cur->next && cur->next->val == val) {
                ListNode* nex = cur->next;
                cur->next = nex->next;
                delete nex;
            } else {
                cur = cur->next;
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
