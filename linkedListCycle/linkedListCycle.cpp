#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main()
{
    int a[5] = {4, 3, 2, 3, 4};
    ListNode *l = new ListNode(a[0]);
    ListNode *tail = l;
    ListNode *t = NULL;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = temp;
        if (i == 2)
            t = temp;
    }
    tail->next = t;
    Solution s;
    cout << s.hasCycle(l) << endl;
    ListNode *h = l;
    tail->next = NULL;
    while (h) {
        ListNode *p = h;
        h = h->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;
    return 0;
}
