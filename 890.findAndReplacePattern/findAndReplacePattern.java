class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> res = new ArrayList<>();
        List<Integer> sigP = sig(pattern);
        for (String word : words) {
            if (word.length() != pattern.length()) continue;
            List<Integer> sigW = sig(word);
            if (sigP.equals(sigW)) res.add(word);
        }
        return res;
    }

    private List<Integer> sig(String str) {
        List<Integer> res = new ArrayList<>();
        Map<Character, Integer> m = new HashMap<>();
        for (char c : str.toCharArray()) {
            m.putIfAbsent(c, m.size());
            res.add(m.get(c));
        }
        return res;
    }
}