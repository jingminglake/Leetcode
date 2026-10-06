class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> groups = new HashMap<>();
        for (String w : strs) {
            char[] arr = w.toCharArray();
            Arrays.sort(arr);
            String key = new String(arr);

            // 写法 B：26 格计数，O(w)，值域小用数组（上一轮的 128 同理）
        // int[] cnt = new int[26];
        // for (char c : w.toCharArray()) cnt[c - 'a']++;
        // String key = Arrays.toString(cnt);
           groups.computeIfAbsent(key, x -> new ArrayList<>()).add(w);
        }
        return new ArrayList<>(groups.values());
    }
}