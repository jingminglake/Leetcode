class Solution {
    public int subarraySum(int[] nums, int k) {
        int res = 0;
        if (nums == null || nums.length == 0)
            return res;
        int[] preSum = new int[nums.length + 1];
        preSum[0] = 0;
        for (int i = 0; i < nums.length; i++)
            preSum[i + 1] = preSum[i] + nums[i];
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < preSum.length; i++) {
            if (m.containsKey(preSum[i] - k))
                res += m.get(preSum[i] - k);
            if (!m.containsKey(preSum[i]))
                m.put(preSum[i], 1);
            else
                m.put(preSum[i], m.get(preSum[i]) + 1);
        }
        return res;
    }
}
