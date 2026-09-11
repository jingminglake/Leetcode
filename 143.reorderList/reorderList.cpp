#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* mid = findMid(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseLinklist(l2);
        mergeList(l1, l2);
    }
    
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseLinklist(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* new_head = reverseLinklist(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
    
    void mergeList(ListNode* l1, ListNode* l2) {
        while (l2) {
            ListNode* nex_l2 = l2->next;
            l2->next = l1->next;
            l1->next = l2;
            l1 = l1->next->next;
            l2 = nex_l2;
        }
    }
};

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    ListNode *l = new ListNode(a[0]);
    ListNode *tail = l;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = temp;
    }
    Solution s;
    s.reorderList(l);
    ListNode *h = l;
    while (h) {
        ListNode *p = h;
        h = h->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;
    return 0;
}
