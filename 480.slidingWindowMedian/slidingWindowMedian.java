class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        Comparator<Integer> comparator = (a, b) -> nums[a] != nums[b] ? Integer.compare(nums[a], nums[b]) : a - b;
        TreeSet<Integer> left = new TreeSet<>(comparator.reversed());
        TreeSet<Integer> right = new TreeSet<>(comparator);
        for (int i = 0; i < k; i++) {
            left.add(i);
        }
        balance(left, right);
        double[] res = new double[nums.length - k + 1];
        int resIndex = 0;
        res[resIndex++] = getMedian(k, nums, left, right);
        for (int i = k; i < nums.length; i++) {
            // remove i - k
            if (left.contains(i - k)) left.remove(i - k);
            else right.remove(i - k);
            // add i
            right.add(i);
            left.add(right.pollFirst());
            balance(left, right);
            res[resIndex++] = getMedian(k, nums, left, right);
        }
        return res;
    }
    
    private void balance(TreeSet<Integer> left, TreeSet<Integer> right) {
        while (left.size() > right.size() + 1) {
            right.add(left.pollFirst());
        }
    }
    
    private double getMedian(int k, int[] nums, TreeSet<Integer> left, TreeSet<Integer> right) {
        if (k % 2 == 0) return ((double)nums[left.first()] + nums[right.first()]) / 2;
        else return (double) nums[left.first()];
    }
}
