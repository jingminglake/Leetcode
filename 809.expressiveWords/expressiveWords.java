class Solution {
    public int expressiveWords(String S, String[] words) {
        if (S == null || words == null) { 
            return 0;
        }
        int res = 0;
        for (String word : words) {
            if (stretchy(S, word)) {
                res++;
            }
        }
        return res;
    }
    
    private boolean stretchy(String S, String word) {
        if (word == null) {
            return false;
        }
        
        int i = 0;
        int j = 0;
        while (i < S.length() && j < word.length()) {
            if (S.charAt(i) == word.charAt(j)) {
                int repS = getRepeated(S, i);
                int repW = getRepeated(word, j);
                //System.out.println(repS + " " + repW);
                if (repS < repW || (repS != repW && repS < 3)) {
                    return false;
                }
                i += repS;
                j += repW;
            } else {
                return false;
            }
        }
        return i == S.length() && j == word.length();
    }
    
    private int getRepeated(String S, int index) {
        if (S == null) {
            return 0;
        }
        int i = index + 1;
        int cnt = 1;
        while (i < S.length()) {
            if (S.charAt(i) == S.charAt(i - 1)) {
                cnt++;
            } else {
                break;
            }
            i++;
        }
        return cnt;
    }
}
