class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> m = new HashMap<>();
        int res = 0;
        int left = 0, right = 0;
        while (right < s.length()) {
            char c = s.charAt(right);
            if (m.containsKey(c) && m.get(c) >= left) {
                left = m.get(c) + 1;
            } 
            m.put(c, right);
            res = Math.max(res, right - left + 1);
            right++;
        }
        return res;
    }
}