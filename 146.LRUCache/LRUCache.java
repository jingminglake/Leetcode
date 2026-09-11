class DLinkedNode {
    public DLinkedNode(int key, int val) {
        this.key = key;
        this.val = val;
        prev = next = null;
    }
    int key;
    int val;
    DLinkedNode prev;
    DLinkedNode next;
}
class LRUCache {
    public LRUCache(int capacity) {
        count = 0;
        this.capacity = capacity;
        head = new DLinkedNode(0, 0);
        tail = new DLinkedNode(0, 0);
        head.next = tail;
        tail.prev = head;
        m = new HashMap<Integer, DLinkedNode>();
    }
    private void addNodeAtHead(DLinkedNode node) {
        head.next.prev = node;
        node.next = head.next;
        head.next = node;
        node.prev = head;
    }
    private void removeNode(DLinkedNode node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    private void moveToHead(DLinkedNode node) {
        removeNode(node);
        addNodeAtHead(node);
    }
    public int get(int key) {
        int res = -1;
        if (m.containsKey(key)) {
            DLinkedNode node = m.get(key);
            res = node.val;
            moveToHead(node);
        }
        return res;
    }
    
    public void put(int key, int value) {
        if (m.containsKey(key)) {
            DLinkedNode node = m.get(key);
            node.val = value;
            moveToHead(node);
        } else {
            if (count == capacity) {
                DLinkedNode lastNode = tail.prev;
                m.remove(lastNode.key);
                removeNode(lastNode);
                count--;
            }
            DLinkedNode newNode = new DLinkedNode(key, value);
            addNodeAtHead(newNode);
            m.put(key, newNode);
            count++;
        }
    }
    private int count;
    private int capacity;
    private DLinkedNode head;
    private DLinkedNode tail;
    private Map<Integer, DLinkedNode> m;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
