class Solution {
    public String modifyString(String s) {
        char[] ss = s.toCharArray();
        for (int i = 0; i < ss.length; i++) {
            if (ss[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if ( (i - 1 < 0 || c != ss[i - 1]) && (i + 1 >= ss.length || c != ss[i + 1]) ) {
                        ss[i] = c;
                    }
                }
            }
        }
        return new String(ss);
    }
}