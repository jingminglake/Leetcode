class Solution {
    public int compress(char[] chars) {
        int last = 0;
        int i = 0;
        while (i < chars.length) {
            chars[last++] = chars[i++];
            int len = 1;
            while (i < chars.length && chars[i] == chars[i - 1]) {
                len++;
                i++;
            }
            //System.out.println(len + "===" + i);
            if (len > 1) {
                List<Character> digits = getDigits(len);
                for (char c : digits) {
                    chars[last++] = c;
                }
            }
        }
        return last;
    }
    
    private List<Character> getDigits(int len) {
        List<Character> res = new LinkedList<>();
        while (len != 0) {
            res.add(0, (char)('0' + len % 10) );
            len /= 10;
        }
        return res;
    }
}
