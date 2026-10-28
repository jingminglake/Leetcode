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
    public boolean isPalindrome(ListNode head) {
        ListNode mid = findMid(head);
        // reverse second half part
        ListNode l2 = mid.next; // head of second part
        mid.next = null; // cut the first half
        l2 = reverse(l2); // reverse

        // compare first and second
        return compareHelper(head, l2);
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
        ListNode cur = head; // point to the first node of non reverse part

        while (cur != null) {
            ListNode tmp = cur.next;
            cur.next = newHead;
            newHead = cur;
            cur = tmp;
        }
        return newHead;
    }

    // [1, 2, 3] + [1, 2]
    private boolean compareHelper(ListNode l1, ListNode l2) {
        while (l2 != null) {
            if (l1.val != l2.val) return false;
            l1 = l1.next;
            l2 = l2.next;
        }
        return true;
    }
}