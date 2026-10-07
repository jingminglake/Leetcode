class Solution {
    public boolean isIsomorphic(String s, String t) {
        return sig(s).equals(sig(t));
    }

    private String sig(String str) {
        Map<Character, Integer> m = new HashMap<>();
        StringBuilder sb = new StringBuilder();
        for (char c : str.toCharArray()) {
            m.putIfAbsent(c, m.size());
            sb.append(m.get(c)).append(',');
        }
        return sb.toString();
    }
}