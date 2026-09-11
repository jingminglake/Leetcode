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
        head_ = head;
        srand(time(0));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = 0, len = 0;
        ListNode* cur = head_;
        while (cur) {
            len++;
            if (rand() % len == 0)
                res = cur->val;
            cur = cur->next;
        }
        return res;
    }
    ListNode *head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
