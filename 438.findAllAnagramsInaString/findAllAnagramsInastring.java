class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        int[] cntP = new int[26];
        for (int i = 0; i < p.length(); i++) cntP[p.charAt(i) - 'a']++;

        int[] cntS = new int[26];
        for (int i = 0; i <= s.length() - p.length(); i++) {
            if (i == 0) {
                for (int j = 0; j < p.length(); j++) {
                    cntS[s.charAt(j) - 'a']++;
                }
            } else {
                cntS[s.charAt(i - 1) - 'a']--;
                cntS[s.charAt(i + p.length() - 1) - 'a']++;
            }
            
            if (Arrays.equals(cntS, cntP)) res.add(i);
        }
        return res;
    }
}