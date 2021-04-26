class Solution {
    public int findLUSlength(String[] strs) {
        Arrays.sort(strs, (s1, s2) -> { 
            if (s1.length() == s2.length()) {
                return s1.compareTo(s2);
            } else {
                return s2.length() - s1.length();
            }
        });
        Set<String> s = new HashSet<>();
        for (int i = 0; i < strs.length; i++) {
            if (i + 1 < strs.length && strs[i + 1].equals(strs[i])) {
                s.add(strs[i]);
                continue;
            }
            if (s.contains(strs[i])) {
                continue;
            }
            if (isOneSub(s, strs[i])) {
                s.add(strs[i]);
                continue;
            } else {
                return strs[i].length();
            }
        }
        return -1;
    }
    
    private boolean isOneSub(Set<String> s, String str) {
        for (String str1 : s) {
            if (isSubsequence(str1, str)) {
                return true;
            }
        }
        return false;
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
