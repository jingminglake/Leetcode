class Solution {
    public boolean wordPattern(String pattern, String s) {
        Map<Character, String> p2w = new HashMap<>();
        Map<String, Character> w2p = new HashMap<>();
        String[] words = s.split(" ");
        if (pattern.length() != words.length) return false;
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            String word = words[i];
            if (!p2w.containsKey(c)) {
                p2w.put(c, words[i]); // a -> dog
                if (w2p.containsKey(words[i])) return false;
                else w2p.put(words[i], c); // dog -> a
            } else {
                String value = p2w.get(c);
                if (!word.equals(value)) return false;
                //if (!w2p.containsKey(word) || !w2p.get(word).equals(c)) return false;
            }
        }
        return true;
    }
}