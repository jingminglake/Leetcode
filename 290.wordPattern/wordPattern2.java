class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] chars = pattern.split("");
        String[] words = s.split(" ");
        if (chars.length != words.length) return false;
        String sigP = sig(chars);
        String sigW = sig(words);
        return sigP.equals(sigW);
    }

    private String sig(String[] seq) {
        Map<String, Integer> m = new HashMap<>();
        StringBuilder sb = new StringBuilder();
        for (String s : seq) {
            if (!m.containsKey(s)) {
                m.put(s, m.size()); 
            } 
            sb.append(m.get(s)).append(","); // dog cat cat dog -> 0,1,1,0,
        }
        return sb.toString();
    }
}