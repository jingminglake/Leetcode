class Solution {
    public String longestPalindrome(String s) {
        int start = 0;
        int curMaxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            int oddLength = expandFromCenter(s, i, i);
            if (oddLength > curMaxLen) {
                start = i - (oddLength - 1) / 2;
                curMaxLen = oddLength;
            }
            int evenLength = expandFromCenter(s, i, i + 1);
            if (evenLength > curMaxLen) {
                start = i - evenLength / 2 + 1;
                curMaxLen = evenLength;
            }
        }
        return s.substring(start, start + curMaxLen);
    }

    private int expandFromCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }
}