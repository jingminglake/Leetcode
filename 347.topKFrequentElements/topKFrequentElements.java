class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> numToCnt = new HashMap<>();
        for (int n : nums) {
            numToCnt.put(n, numToCnt.getOrDefault(n, 0) + 1);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[1], b[1])); // {num, cnt}
        
        for (Map.Entry<Integer, Integer> entry : numToCnt.entrySet()) {
            pq.offer(new int[]{entry.getKey(), entry.getValue()});
            if (pq.size() > k) pq.poll();
        }
        int[] res = new int[k];
        int index = k - 1;
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            res[index--] = top[0];
        }
        return res;
    }
}