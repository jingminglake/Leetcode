class MedianFinder {

    /** initialize your data structure here. */
    public MedianFinder() {
        leftQ = new PriorityQueue<Integer>(1000, Collections.reverseOrder());
        rightQ = new PriorityQueue<Integer>();
    }
    
    public void addNum(int num) {
        leftQ.add(num);
        rightQ.add(leftQ.poll());
        if (leftQ.size() < rightQ.size()) {
            leftQ.add(rightQ.poll());
        }
        size++;
    }
    
    public double findMedian() {
        if (size % 2 == 0) {
            return (leftQ.peek() + rightQ.peek()) / 2.0;
        } else {
            return leftQ.peek();
        }
    }
    
    Queue<Integer> leftQ;
    Queue<Integer> rightQ;
    int size;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
