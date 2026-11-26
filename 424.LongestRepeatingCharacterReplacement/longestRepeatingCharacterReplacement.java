class Solution {
    public int characterReplacement(String s, int k) {
        int res = 0;
        int len = s.length();
        int[] freq = new int[26];

        int left = 0;
        int right = 0;
        int maxFreq = 0; // most freq char cnt in the window
        while (right < len) {
            char c = s.charAt(right);
            freq[c - 'A']++;
            maxFreq = Math.max(maxFreq, freq[c - 'A']);

            // while window is not valid, move left until it valid
            int needChange = right - left + 1 - maxFreq;
            while (needChange > k) {
                char leftC = s.charAt(left);
                freq[leftC - 'A']--; // -- not affect maxFreq
                left++;

                needChange = right - left + 1 - maxFreq; 
            }
            res = Math.max(res, right - left + 1);
            right++;
        }
        return res;
    }
}