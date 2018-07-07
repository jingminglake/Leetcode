#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *prev = nullptr;
        while (head) {
            ListNode *nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }
};

int main()
{
    int a[5] = {0, 1, 2, 3, 4};
    ListNode *l = new ListNode(a[0]);
    ListNode *tail = l;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = temp;
    }
    Solution s;
    ListNode * h = s.reverseList(l);
    while (h) {
        ListNode *p = h;
        h = h->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;

    return 0;
}
