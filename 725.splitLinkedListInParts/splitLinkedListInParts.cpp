#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    vector<ListNode*> res(k, nullptr);
    int len = 0;
    for (ListNode* node = root; node; node = node->next)
      len++;
    int n = len / k, r = len % k; // n : minimum guaranteed part size; r : extra nodes spread to the first r parts;
    ListNode* node = root, *prev = nullptr;
    for (int i = 0; node && i < k; i++, r--) {
      res[i] = node;
      for (int j = 0; j < n + (r > 0); j++) {
	prev = node;
	node = node->next;
      }
      prev->next = nullptr;
    }
    return res;
  }
};

int main()
{
  int a[5] = {1, 2, 5, 8, 10};
  ListNode *l = new ListNode(a[0]);
  ListNode *tail = l;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    ListNode *temp = new ListNode(a[i]);
    tail->next = temp;
    tail = temp;
  }
  ListNode *l1 = l;
  Solution s;
  vector<ListNode*> res = s.splitListToParts(l1, 3);
  for (ListNode* n : res) {
    cout << n->val << " ";
  }
  cout << endl;
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
