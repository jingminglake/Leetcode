#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(), G.end());
        int res = 0;
        while (head) {
            if (s.count(head->val) && (head->next == nullptr || !s.count(head->next->val)))
                res++;
            head = head->next;
        }
        return res;
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
  vector<int> G = {0, 3, 1, 4};
  cout << s.numComponents(l, G) << endl;
  ListNode * h = l;
  while (h) {
    ListNode *p = h;
    h = h->next;
    cout << "delete " << p->val << " ";
    delete p;
  }
  cout << endl;

  return 0;
}
