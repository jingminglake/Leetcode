class Solution {
    public String longestWord(String[] words) {
        Set<String> wordSet = new HashSet<>();
        for (String word : words) wordSet.add(word);
        Map<String, Boolean> buildable = new HashMap<>();
        String longestWord = new String();
        for (String word : words) {
            if (word.length() < longestWord.length()) continue;
            if (word.length() == longestWord.length() && word.compareTo(longestWord) >= 0) continue;
            if (dfs(word, buildable, wordSet)) {
                longestWord = word;
            }
        }
        return longestWord;
    }
    
    public boolean dfs(String word, Map<String, Boolean> buildable, Set<String> wordSet) {
        if (word.length() == 1 && wordSet.contains(word)) {
            buildable.put(word, true);
            return true;
        }
        if (buildable.containsKey(word)) {
            return buildable.get(word);
        }
        if (!wordSet.contains(word)) {
            buildable.put(word, false);
            return false;
        }
        String prev = word.substring(0, word.length() - 1);
        boolean res = dfs(prev, buildable, wordSet);
        buildable.put(word, res);
        return res;
    }
}
