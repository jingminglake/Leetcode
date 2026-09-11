class Solution {
    public String reverseString(String s) {
        char[] ss = s.toCharArray();
        int left = 0, right = ss.length - 1;
        while (left < right) {
            char temp = ss[left];
            ss[left] = ss[right];
            ss[right] = temp;
            left++;
            right--;
        }
        return new String(ss);
    }
}
