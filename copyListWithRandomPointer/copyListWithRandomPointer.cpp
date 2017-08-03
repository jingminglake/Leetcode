#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution{
public:
  RandomListNode* copyRandomList(RandomListNode* head) {
    if (!head)
      return NULL;
    RandomListNode* l = new RandomListNode(head->label);
    RandomListNode* tail = l;
    unordered_map<RandomListNode*, RandomListNode*> m;
    m.insert(make_pair(head, l));
    RandomListNode* h = head->next;
    while (h) {
      RandomListNode* temp = new RandomListNode(h->label);
      m.insert(make_pair(h, temp));
      tail->next = temp;
      tail = temp;
      h = h->next;
    }
    h = head;
    RandomListNode* h2 = l;
    while (h) {
      unordered_map<RandomListNode*, RandomListNode*>::iterator it = m.find(h->random);
      if (it != m.end())
	h2->random = it->second;
      h = h->next;
      h2 = h2->next;
    }
    return l;
  }

};

int main()
{
  int a[5] = {0, 1, 2, 3, 4};
  RandomListNode *l = new RandomListNode(a[0]);
  RandomListNode *tail = l;
  tail->random = tail;
  for (int i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
    RandomListNode *temp = new RandomListNode(a[i]);
    tail->next = temp;
    temp->random = temp;
    tail = temp;
  }
  Solution s;
  RandomListNode* res =  s.copyRandomList(l);
  while (res) {
    if (res->random)
      cout << res->random->label << " ";
    res = res->next;
  }
  cout << endl;
  return 0;
}
