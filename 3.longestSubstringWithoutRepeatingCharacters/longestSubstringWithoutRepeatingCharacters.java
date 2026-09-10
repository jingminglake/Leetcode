class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0;
        Map<Character, Integer> map = new HashMap<>();
        int left = 0, right = 0;
        while (right < s.length()) {
            char c = s.charAt(right);
            if (map.containsKey(c)) {
                left = Math.max(left, map.get(c) + 1);
            }
            res = Math.max(res, right - left + 1);
            map.put(c, right);
            right++;
        }
        return res;
    }
}
