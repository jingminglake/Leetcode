  //        
  // level 3: -Inf ----------------------------> 4
  // level 2: -Inf ------------> 2 ------------> 4
  // level 1: -Inf ----> 1 ----> 2 ------------> 4
  // level 0: -Inf ----> 1 ----> 2 ----> 3 ----> 4
class Skiplist {
    
    private static final class Node {
        private final int val;
        private Node next, down;
        
        private Node(int val) {
            this.val = val;
        }
    }
    
    private final Random rand = new Random();
    
    private boolean flipCoin() {
        return rand.nextDouble() < 0.5;
    }

    public Skiplist() {
        
    }
    
    public boolean search(int target) {
        Node cur = leftTopHead;
        while (cur != null) {
            while (cur.next != null && cur.next.val < target)
                cur = cur.next;
            if (cur.next != null && cur.next.val == target)
                return true;
            cur = cur.down;
        }
        return false;
    }
    
    public void add(int num) {
        Stack<Node> stk = new Stack<>();
        // step1: find first lessThan Node in all level
        Node cur = leftTopHead;
        while (cur != null) {
            while (cur.next != null && cur.next.val < num) {
                cur = cur.next;
            }
            stk.push(cur);
            cur = cur.down;
        }
        
        // step2: 100% chance insert at level 0 and 50% chance to insert from level 1 to level N
        boolean shouldInsert = true;
        Node lastInsertNode = null;
        while (!stk.isEmpty() && shouldInsert) {
            Node prev = stk.pop();
            Node n = new Node(num);
            n.next = prev.next;
            prev.next = n;
            n.down = lastInsertNode;
            lastInsertNode = n;
            shouldInsert = flipCoin();
        }
        
        // step4: if insert happens in level N, then create level N + 1
        if (shouldInsert) {
            Node head = new Node(Integer.MIN_VALUE);
            head.down = leftTopHead;
            leftTopHead = head;
        }
    }
    
    public boolean erase(int num) {
        boolean found = false;
        Node cur = leftTopHead;
        while (cur != null) {
            while (cur.next != null && cur.next.val < num) {
                cur = cur.next;
            }
            if (cur.next != null && cur.next.val == num) {
                found = true;
                cur.next = cur.next.next;
            }
            cur = cur.down;
        } 
        return found;
    }
    
    private Node leftTopHead = new Node(Integer.MIN_VALUE);
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist obj = new Skiplist();
 * boolean param_1 = obj.search(target);
 * obj.add(num);
 * boolean param_3 = obj.erase(num);
 */
