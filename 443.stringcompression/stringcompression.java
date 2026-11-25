class Solution {
    public int compress(char[] chars) {
        int len = chars.length;
        int i = 0;
        int w = 0; // next write index
        while (i < len) {
            char cur = chars[i];
            int j = i;
            while (j < len && chars[j] == cur) {
                j++;
            }
            chars[w++] = cur;
            int cnt = j - i;
            if (cnt > 1) {
                for (char d : String.valueOf(cnt).toCharArray()) {
                    chars[w++] = d;
                }
            }
            i = j;
        }
        return w;
    }
}