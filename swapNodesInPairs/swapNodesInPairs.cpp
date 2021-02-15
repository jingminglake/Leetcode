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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *new_head = head->next;
        ListNode* sub_head = swapPairs(head->next->next);
        head->next = sub_head;
        new_head->next = head;
        return new_head;
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
    head = s.swapPairs(head);
    while (head != NULL) {
        ListNode *p = head;
        head = head->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;
    return 0;
}
