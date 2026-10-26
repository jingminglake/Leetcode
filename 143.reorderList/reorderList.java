/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

/*

 1 -> 2 -> 3 -> 4 -> 5

 5 -> 4 -> 3 -> 2 -> 1

 1 -> 5 -> 2 -> 4 -> 3

*/
class Solution {
    public void reorderList(ListNode head) {
        int size = 0;
        Stack<ListNode> stk = new Stack();
        ListNode cur = head;
        while (cur != null) {
            stk.push(cur);
            cur = cur.next;
            size++;
        }
        if (size == 1) return;

        ListNode dummy = new ListNode(0);
        dummy.next = head; // keep head
        ListNode l1 = head;
        ListNode l2 = stk.pop();
        cur = dummy;
        for (int i = 0; i < size / 2; i++) {
            // add l1
            cur.next = l1;
            cur = cur.next;
            l1 = l1.next;
            // add l2
            cur.next = l2;
            cur = cur.next;
            l2 = stk.pop();
        }
        if (size % 2 != 0) {
            cur.next = l1;
            cur = cur.next;
        }
        cur.next = null;
    }
}