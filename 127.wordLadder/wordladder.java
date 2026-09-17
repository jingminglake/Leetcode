class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        if (!wordSet.contains(endWord)) return 0;

        Queue<String> q = new ArrayDeque<>();
        q.add(beginWord);
        if (wordSet.contains(beginWord)) wordSet.remove(beginWord);
        int res = 1;
        
        while (!q.isEmpty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                String curWord = q.poll();
                char[] chars = curWord.toCharArray();
                // all the next trans
                for (int j = 0; j < curWord.length(); j++) {
                     char c = curWord.charAt(j);
                     // replace c with other char
                     for (char nextC = 'a'; nextC <= 'z'; nextC++) {
                        if (nextC == c) continue;
                        chars[j] = nextC;
                        String nextWord = new String(chars);

                        // find endWord or add to queue
                        if (wordSet.contains(nextWord)) {
                            if (nextWord.equals(endWord)) return res + 1;
                            wordSet.remove(nextWord);
                            q.add(nextWord);
                        }
                     }
                     // recover
                    chars[j] = c;
                }
            }
            res++;
        }
        return 0;
    }
}