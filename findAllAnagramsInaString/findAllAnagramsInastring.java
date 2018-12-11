class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new LinkedList<>();
        if (s == null || p == null)
            return res;
        int sLen = s.length(), pLen = p.length();
        if (sLen < pLen)
            return res;
        int left = 0, right = 0;
        Map<Character, Integer> m = new HashMap<>();
        for (char c : p.toCharArray()) {
            m.put(c, m.getOrDefault(c, 0) + 1);
        }
        int count = m.size();
        while (right < sLen) {
            char c = s.charAt(right);
            if (m.containsKey(c)) {
                m.put(c, m.get(c) - 1);
                if (m.get(c) == 0) count--;
            }
            right++;
            while (count == 0) {
                c = s.charAt(left);
                if (m.containsKey(c)) {
                    m.put(c, m.get(c) + 1);
                    if (m.get(c) > 0) count++;
                }
                if (right - left == p.length())
                    res.add(left);
                left++;
            }
        }
        return res;
    }
}
