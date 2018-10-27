import java.util.*;
class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}
 
public class LinkedListCycle {
    public boolean hasCycle(ListNode head) {
        if (head == null)
            return false;
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                return true;
        }
        return false;
    }
	public static void main(String[] args) {
		int a[] = {4,3,2,3,4};
		ListNode l = new ListNode(a[0]);
		ListNode tail = l;
		ListNode t = null;
		for (int i = 1; i < a.length; i++) {
			ListNode temp = new ListNode(a[i]);
			tail.next = temp;
			tail = temp;
			if (i == 2)
				t = temp;
		}
		tail.next = t;
		LinkedListCycle s = new LinkedListCycle();
		System.out.println(s.hasCycle(l));
	}
}
