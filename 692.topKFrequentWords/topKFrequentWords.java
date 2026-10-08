class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> wordToCnt = new HashMap<>();
        for (String word : words) {
            wordToCnt.put(word, wordToCnt.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<>((a, b) -> {
            String wordA = a.getKey(), wordB = b.getKey();
            int cntA = a.getValue(), cntB = b.getValue();
            if (cntA != cntB) return Integer.compare(cntA, cntB); // minHeap
            else return wordB.compareTo(wordA); 
        });

        for (Map.Entry<String, Integer> entry : wordToCnt.entrySet()) {
            pq.offer(entry);
            if (pq.size() > k) pq.poll();
        }
        List<String> res = new ArrayList<>();
        while (!pq.isEmpty()) {
            Map.Entry<String, Integer> top = pq.poll();
            res.add(top.getKey());
        }
        Collections.reverse(res);
        return res;
    }
}