class Solution {
    public boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }

            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }

            if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) return false;
            left++;
            right--;
        }
        return true;
    }
}

/*
s = ".,"
left = 0, right = 1
left = 0 < right = 1 true, !Character.isLetterOrDigit('.') true left = 1, 1 < 1 false 
left = 1 < right = 1 fale

charAt(1) != charAt(1) false

left = 2, right = 0

2 < 0 false return true

*/