class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) return "";

        int[] need = new int[128];
        int[] window = new int[128];

        int required = 0; // how many distinct char
        for (char c : t.toCharArray()) {
            if (need[c] == 0) required++;
            need[c]++;
        }

        int formed = 0;
        int left = 0;
        int right = 0;
        int resStart = 0;
        int minLength = Integer.MAX_VALUE;

        while (right < s.length()) {
            char incoming = s.charAt(right);
            window[incoming]++;

            if (need[incoming] > 0 && need[incoming] == window[incoming]) {
                formed++; // formed when character num matches
            }

            // move left if match
            while (formed == required) {
                int curLen = right - left + 1;
                if (curLen < minLength) {
                    minLength = curLen;
                    resStart = left;
                }

                // move left to reduce window size
                char outgoing = s.charAt(left);
                window[outgoing]--;
                left++;

                if (need[outgoing] > 0 && need[outgoing] > window[outgoing]) {
                    formed--;
                }
            }
            right++;
        }
        if (minLength == Integer.MAX_VALUE) return "";
        return s.substring(resStart, resStart + minLength);
    }
}