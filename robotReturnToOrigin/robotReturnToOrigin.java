class Solution {
    public boolean judgeCircle(String moves) {
        Map<Character, Integer> m = new HashMap<>();
        for (char c : moves.toCharArray()) {
            m.put(c, m.getOrDefault(c, 0) + 1);
        }
        return m.getOrDefault('R', 0).equals(m.getOrDefault('L', 0)) 
            && m.getOrDefault('D', 0).equals(m.getOrDefault('U', 0));
    }
}
