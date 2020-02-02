#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    class Compare {
    public:
        bool operator() (const ListNode* l1, const ListNode* l2) const {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (ListNode* l : lists) {
            if (l) pq.push(l);
        }
        ListNode dummy(0);
        ListNode* last = &dummy;
        while (!pq.empty()) {
            ListNode* l = pq.top(); pq.pop();
            ListNode* n = new ListNode(l->val);
            last->next = n;
            last = last->next;
            if (l->next) pq.push(l->next);
        }
        return dummy.next;
    }
};

int main()
{
    int a[4] = {2, 3, 4, 7};
    ListNode *l = new ListNode(a[0]);
    ListNode *tail = l;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        ListNode *temp = new ListNode(a[i]);
        tail->next = temp;
        tail = temp;
    }
    ListNode *l1 = new ListNode(a[0]);
    ListNode *tail1 = l1;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        ListNode *temp = new ListNode(a[i]);
        tail1->next = temp;
        tail1 = temp;
    }
    ListNode *l2 = new ListNode(a[0]);
    ListNode *tail2 = l2;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        ListNode *temp = new ListNode(a[i]);
        tail2->next = temp;
        tail2 = temp;
    }
    vector<ListNode*> vec;
    vec.push_back(l);
    vec.push_back(l1);
    vec.push_back(l2);
    Solution s;
    ListNode *h = s.mergeKLists(vec);
    while (h) {
        ListNode *p = h;
        h = h->next;
        cout << "delete " << p->val << " ";
        delete p;
    }
    cout << endl;
    return 0;
}
