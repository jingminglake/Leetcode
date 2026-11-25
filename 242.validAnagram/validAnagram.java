class Solution {
    public boolean isAnagram(String s, String t) {
        int lenS = s.length();
        int lenT = t.length();
        if (lenS != lenT) return false;
        int[] ms = new int[26];
        int[] mt = new int[26];
        for (int i = 0; i < lenS; i++) {
            char sc = s.charAt(i);
            char tc = t.charAt(i);
            ms[sc - 'a']++;
            mt[tc - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (ms[i] != mt[i]) return false;
        }
        return true;
    }
}