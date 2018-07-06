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
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *temp = nullptr;
            while (prev && cur && cur->val == prev->val) {
                temp = cur;
                cur = cur->next;
                prev->next = cur;
                delete temp;
            }
            if (cur) {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main()
{
    int a[5] = {1, 1, 2, 3, 3};
    ListNode *l = new ListNode(a[0]);
    ListNode *tail = l;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = temp;
    }
    Solution s;
    ListNode * h = s.deleteDuplicates(l);;
    while (h) {
        ListNode *p = h;
        h = h->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;

    return 0;
}
