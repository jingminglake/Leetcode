class Solution {
    public int myAtoi(String s) {
        int length = s.length();
        int i = 0;
        
        // skip whitespace
        while (i < length && s.charAt(i) == ' ') {
            i++;
        }

        // singedness
        int sign = 1;
        if (i < length && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            if (s.charAt(i) == '-') sign = -1;
            i++;
        }

        long res = 0;

        // conversion
        while (i < length) {
            char c = s.charAt(i);
            if (c < '0' || c > '9') break;
            int digit = c - '0';
            res = res * 10 + digit;
            long signedRes = res * sign;
            if (signedRes > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            } else if (signedRes < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
            i++;
        }
        return (int) (sign * res);
    }
}