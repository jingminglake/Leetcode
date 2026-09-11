/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;
        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(lists.length, new Comparator<ListNode>() {
            @Override
            public int compare(ListNode n1, ListNode n2) {
                return n1.val - n2.val;
            }
        });
        for (ListNode list : lists) {
            if (list != null)
                pq.add(list);
        }
        ListNode dummy = new ListNode(0);
        ListNode last = dummy;
        while (!pq.isEmpty()) {
            ListNode n = pq.poll();
            last.next = n;
            last = last.next;
            if (n.next != null)
                pq.add(n.next);
        }
        return dummy.next;
    }
}
