class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0;
        int left = 0;
        int[] charCnt = new int[128];
        for (int right = 0; right < s.length(); right++) {
            char cRight = s.charAt(right);
            charCnt[cRight]++;

            while (charCnt[cRight] != 1) {
                char cLeft = s.charAt(left);
                charCnt[cLeft]--;
                left++;
            }

            res = Math.max(res, right - left + 1);
        }
        return res;
    }
}