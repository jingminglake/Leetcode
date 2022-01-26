class Solution {
    class Tuple implements Comparable<Tuple> {
        int x, y, val;
        public Tuple (int x, int y, int val) {
            this.x = x;
            this.y = y;
            this.val = val;
        }
        
        @Override
        public int compareTo(Tuple t) {
            return this.val - t.val;
        }
    }
    
    // public void swapList(List<Integer> l1, List<Integer> l2) {
    //     List<Integer> tmp = new ArrayList<>(l1);
    //     l1.clear();
    //     l1.addAll(l2);
    //     l2.clear();
    //     l2.addAll(tmp);
    // }
        
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        Queue<Tuple> pq = new PriorityQueue<Tuple>();
        int n1 = nums1.length, n2 = nums2.length;
        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        if (n1 <= n2) {
            for (int n : nums1) l1.add(n);
            for (int n : nums2) l2.add(n);
        } else {
            for (int n : nums1) l2.add(n);
            for (int n : nums2) l1.add(n);
        }
        
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < l1.size(); i++) {
            pq.offer(new Tuple(i, 0, l1.get(i) + l2.get(0)));
        }
        
        for (int i = 0; i < Math.min(k, n1 * n2); i++) {
            Tuple t = pq.poll();
            if (n1 <= n2) {
                res.add(new ArrayList<>(Arrays.asList(l1.get(t.x), l2.get(t.y))));
            } else {
                res.add(new ArrayList<>(Arrays.asList(l2.get(t.y), l1.get(t.x))));
            }
            if (t.y + 1 < l2.size()) {
                pq.offer(new Tuple(t.x, t.y + 1, l1.get(t.x) + l2.get(t.y + 1)));
            }
        }
        return res;
    }
}
