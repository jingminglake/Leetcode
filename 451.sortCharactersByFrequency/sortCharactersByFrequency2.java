class Solution {
    public String frequencySort(String s) {
        int[] cnt = new int[128];
        for (char c : s.toCharArray()) cnt[c]++;

        List<Character>[] bucket = new List[s.length() + 1];
        for (char c = 0; c < 128; c++) {
            if (cnt[c] == 0) continue;
            if (bucket[cnt[c]] == null) bucket[cnt[c]] = new ArrayList<>();
            bucket[cnt[c]].add(c);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = s.length(); i >= 1; i--) {
            if (bucket[i] == null) continue;
            for (char c : bucket[i]) {
                for (int k = 0; k < i; k++) {
                    sb.append(c);
                }
            }
        }
        return sb.toString();
    }
}