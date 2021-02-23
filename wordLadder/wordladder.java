class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>();
        for (String word : wordList) wordSet.add(word);
        int res = 0;
        Queue<String> q = new LinkedList<>();
        q.offer(beginWord);
        while (!q.isEmpty()) {
            int q_size = q.size();
            res++;
            for (int i = 0; i < q_size; i++) {
                String curWord = q.poll();
                for (int index = 0; index < curWord.length(); index++) {
                    char[] curWordChars = curWord.toCharArray();
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == curWordChars[index]) continue;
                        curWordChars[index] = c;
                        String nextWord = new String(curWordChars);
                        if (!wordSet.contains(nextWord)) continue;
                        if (nextWord.equals(endWord)) return res + 1;
                        wordSet.remove(nextWord);
                        q.offer(nextWord);
                    }
                }
            }
        }
        return 0;
    }
}
