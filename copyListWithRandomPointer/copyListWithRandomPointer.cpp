#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node dummy(0);
        Node* last = &dummy;
        unordered_map<Node*, Node*> m; // old -> new
        Node* cur = head;
        while (cur) {
            Node* n = new Node(cur->val);
            m[cur] = n;
            last->next = n;
            last = last->next;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return dummy.next;
    }
};

int main()
{
    int a[5] = {0, 1, 2, 3, 4};
    Node *l = new Node(a[0]);
    Node *tail = l;
    tail->random = tail;
    for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
        Node *temp = new Node(a[i]);
        tail->next = temp;
        temp->random = temp;
        tail = temp;
    }
    Solution s;
    Node* res =  s.copyRandomList(l);
    while (res) {
        if (res->random)
            cout << res->random->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
