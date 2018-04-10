/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        h = head;
        srand(time(0));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = h;
        int res = cur->val;
        int i = 1;
        while (cur->next) {
            cur = cur->next;
            if (rand() % (++i) == 0)
                res = cur->val;
        }
        return res;
    }
    ListNode *h;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
