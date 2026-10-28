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
class Solution {

    public int pairSum(ListNode head) {
        ListNode mid = findMid(head); // 5->4->2->1, mid = 4
        ListNode l2 = mid.next; // head of second part
        mid.next = null; // cut in the middle
        l2 = reverse(l2);
        
        return findRes(head, l2); // head: [5, 4], l2: [1, 2]
    }

    private ListNode findMid(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode slow = dummy;
        ListNode fast = dummy;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

    private ListNode reverse(ListNode head) {
        ListNode newHead = null; // point to head of the reversed part
        ListNode cur = head; // point to the first node of the non reverse part
        while (cur != null) {
            ListNode tmp = cur.next;
            cur.next = newHead;
            newHead = cur;
            cur = tmp;
        }
        return newHead;
    }

    // [5,4] ,[1,2]  5+1, 4+2
    private int findRes(ListNode l1, ListNode l2) {
        int res = 0;
        while (l1 != null) {
            res = Math.max(res, l1.val + l2.val);
            l1 = l1.next;
            l2 = l2.next;
        }
        return res;
    }
}