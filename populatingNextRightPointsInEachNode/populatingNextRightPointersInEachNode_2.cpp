#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node* head = root;
        while (head) {
            Node* cur = head;
            while (cur) {
                if (cur->left && cur->right) {
                    cur->left->next = cur->right;
                    if (cur->next)
                        cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            head = head->left;
        }
        return root;
    }
};

int main()
{
    int tree[7] = {1,2,3,4,5,6,7};
    int size = sizeof(tree)/sizeof(tree[0]);
    vector<Node *> vec;
    for (int i = 0; i < size; i++) {
        if (tree[i] != 9999) {
            vec.push_back(new Node(tree[i]));
        } else {
            vec.push_back(NULL);
        }
    }
    for (int i = 0; i < size/2; i++) {
        if(!vec[i])
            continue;
        if (i*2 + 1 < size)
            vec[i]->left = vec[i*2 + 1];
        if (i*2 + 2 < size)
            vec[i]->right = vec[i*2 + 2];
    }
    Solution s;
    s.connect(vec[0]);
    queue<Node*> q;
    Node *t = vec[0];
    while (t) {
        q.push(t);
        t = t->left;
    }
    while (!q.empty()) {
        Node *first = q.front();
        q.pop();
        while (first) {
            cout << first->val << " ";
            first = first->next;
        }
        cout << endl;
    }
    for (Node * tn : vec) {
        delete tn;
    }
    vec.clear();
    return 0;
}
