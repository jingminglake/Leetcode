class Solution {
    public String modifyString(String s) {
        char[] ss = s.toCharArray();
        dfs(ss);
        return String.valueOf(ss);
    }
    
    private boolean dfs(char[] s) {
        boolean flag = true;
        for (char c : s) {
            if (c == '?') {
                flag = false;
                break;
            }
        }
        if (flag) return true;
        for (int i = 0; i < s.length; i++) {
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if ( (i - 1 < 0 || c != s[i - 1]) && (i + 1 >= s.length || c != s[i + 1]) ) {
                        s[i] = c;
                        if (dfs(s)) {
                            return true;
                        }
                        
                    }
                }
                flag = false;
            }
        }
        return false;
    }
}