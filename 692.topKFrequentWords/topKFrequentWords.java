class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> hm = new HashMap<>();
        for (String word : words) {
            if (hm.containsKey(word)) {
                hm.put(word, hm.get(word) + 1);
            } else {
                hm.put(word, 1);
            }
        }
        Comparator<Map.Entry<String, Integer>> comp = (a, b) -> a.getValue() == b.getValue() ?b.getKey().compareTo(a.getKey()) : a.getValue() - b.getValue();
        Queue<Map.Entry<String, Integer>> pq = new PriorityQueue<Map.Entry<String, Integer>>(comp);
        for (Map.Entry<String, Integer> entry : hm.entrySet()) {
            pq.add(entry);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        List<String> res = new ArrayList<>();  
        while (!pq.isEmpty()) res.add(0, pq.poll().getKey());                                                   
        return res;
    }
}
