class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] res = new int[nums1.length];
        if (nums1.length == 0) return res;
    
        Stack<Integer> stk = new Stack(); // index: 0(1) -> 1(3) -> 2(4)
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < nums2.length; i++) {
            int cur = nums2[i];

            while (!stk.isEmpty() && cur > nums2[stk.peek()]) {
                int peekIndex = stk.pop();
                m.put(nums2[peekIndex], cur);
            }

            stk.push(i);
        }
        
        for (int i = 0; i < nums1.length; i++) {
            if (m.containsKey(nums1[i])) res[i] = m.get(nums1[i]);
            else res[i] = -1;
        }
        return res;
    }
}