class Solution {
    public String longestPalindrome(String s) {
        if (s.length() < 2) return s;
        String res = "";
        for (int i = 0; i < s.length() - 1; i++) {
            String pal1 = palindrome(s, i, i);
            if (pal1.length() > res.length()) res = pal1;
            if (s.charAt(i) == s.charAt(i + 1)) {
                String pal2 = palindrome(s, i, i + 1);
                if (pal2.length() > res.length()) res = pal2;
            }
        }
        return res;
    }
    
    public String palindrome(String s, int mid1, int mid2) {
        while (mid1 >= 0 && mid2 < s.length()) {
            if (s.charAt(mid1) == s.charAt(mid2)) {
                mid1--;
                mid2++;
            } else {
                break;
            }
        }
        return s.substring(mid1 + 1, mid2);
    }
}
