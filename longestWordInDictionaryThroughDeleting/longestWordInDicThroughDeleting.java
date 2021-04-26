class Solution {
    public String findLongestWord(String s, List<String> dictionary) {
        String res = "";
        for (String word : dictionary) {
            if (word.length() < res.length() || word.length() > s.length()) continue;
            if (isSubsequence(s, word)) {
                if (word.length() == res.length() && word.compareTo(res) > 0) {
                    continue;
                }
                res = word;
            }
        }
        return res;
    }
    
    private boolean isSubsequence(String s1, String s2) {
        int p1 = 0, p2 = 0;
        while (p1 < s1.length() && p2 < s2.length()) {
            if (s1.charAt(p1) == s2.charAt(p2)) {
                p1++; p2++;
            } else {
                p1++;
            }
        }
        return p2 == s2.length();
    }
}
