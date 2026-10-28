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
    public void reorderList(ListNode head) {
        // find mid node
        ListNode mid = firstMiddle(head);

        // reverse the second half, then no need extra space
        ListNode l2 = mid.next;
        mid.next = null;
        l2 = reverse(l2);

        // merge first and second
        merge(head, l2);
    }

    // 返回第一个中点：[1,2,3,4] → 2，[1,2,3,4,5] → 3
    private ListNode firstMiddle(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode slow = dummy;
        ListNode fast = dummy;
        // find mid node
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    // 反转链表，返回新的头
    private ListNode reverse(ListNode head) { 
        ListNode newHead = null; // point to head of the reversed part
        ListNode cur = head; // point to the first node of the non-reversed part

        while (cur != null) {
            ListNode tmp = cur.next;
            cur.next = newHead;
            newHead = cur;
            cur = tmp;
        }
        return newHead;
    }

    // [1,2,3] + [5, 4] -> [1, 5, 2, 4, 3]
    // [1, 2] + [4, 3] -> [1, 4, 2, 3]
    private void merge(ListNode l1, ListNode l2) {
        while (l2 != null) {
            ListNode nextl1 = l1.next;
            ListNode nextl2 = l2.next;
            
            l1.next = l2;
            l2.next = nextl1;

            l1 = nextl1;
            l2 = nextl2;   
        }
    }
    /*
    [1 -> 2 -> 3], [5 -> 4]

    nextl1 = 2, nextl2 = 4
    1 -> 5
    5 -> 2
    l1 = 2
    l2 = 4


    nextl1 = 3, nextl2 = null
    2 -> 4
    4 -> 3
    l1 = 3
    l2 = null

    l2 == null -> end

    */
}