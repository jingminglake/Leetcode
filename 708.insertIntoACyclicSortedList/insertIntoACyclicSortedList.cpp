#include <iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node *n = new Node(insertVal, nullptr);
            n->next = n;
            return n;
        }
       /* if (head->next == head) {
            Node *n = new Node(insertVal, head);
            head->next = n;
            return head;
        }*/
        Node *prev = nullptr;
        Node *cur = head;
        bool inserted = false;
        while (!prev || prev->next != head) {
            if ((cur->val <= insertVal && cur->next->val >= insertVal) || 
                (cur->val < insertVal && cur->val > cur->next->val) ||
                (cur->next->val > insertVal && cur->val > cur->next->val) ) {
                //cout << "cur-->" << cur->val << endl;
                Node *n = new Node(insertVal, cur->next);
                cur->next = n;
                inserted = true;
                break;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        if (!inserted) {
            Node *n = new Node(insertVal, head);
            prev->next = n;
        }
        return head;
    }
};

void traverse(Node* head) {
    Node *cur = head;
    Node *prev = nullptr;
    while (cur) {
        cout << cur->val << " ";
        prev = cur;
        cur = cur->next;
        delete prev;
        if (cur == head)
            break;
    }
    cout << endl;
}

int main() {
    Solution s;
    Node* head = nullptr;
    head = s.insert(head, 3);
    head = s.insert(head, 5);
    head = s.insert(head, 1);
    head = s.insert(head, 3);
    head = s.insert(head, 0);
    head = s.insert(head, 6);
    traverse(head);
    return 0;
}
