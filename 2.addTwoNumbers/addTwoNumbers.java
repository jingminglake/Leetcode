/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode newHead = new ListNode(0);
        ListNode p1 = l1, p2 = l2;
        ListNode last = newHead;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            int val = (l1 != null ? l1.val : 0) + (l2 != null ? l2.val : 0) + carry;
            carry = val / 10;
            last.next = new ListNode(val % 10);
            last = last.next;
            if (l1 != null)
                l1 = l1.next;
            if (l2 != null)
                l2 = l2.next;
        }
        return newHead.next;
    }
}
