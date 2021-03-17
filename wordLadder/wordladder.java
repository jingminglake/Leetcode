class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>();
        for (String word : wordList) wordSet.add(word);
        
        if (!wordSet.contains(endWord)) return 0;
        
        Queue<String> q = new LinkedList<>();
        q.offer(beginWord);
        wordSet.remove(beginWord);
        int level = 1;
        while (!q.isEmpty()) {
            level++;
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                String cur = q.poll();
                char[] curChars = cur.toCharArray();
                for (int k = 0; k < cur.length(); k++) {
                    char origin = curChars[k]; 
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == curChars[k]) continue;
                        curChars[k] = c;
                        String new_word = new String(curChars);
                        if (!wordSet.contains(new_word)) continue;
                        if (endWord.equals(new_word)) return level;
                        q.offer(new_word);
                        wordSet.remove(new_word);
                    }
                    curChars[k] = origin; 
                }
            }
        }
        return 0;
    }
}
