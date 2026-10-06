class Solution {
    public String frequencySort(String s) {
        int[] cnt = new int[128];
        for (char c : s.toCharArray()) cnt[c]++;

        List<Character> chars = new ArrayList<>();
        for (char c = 0; c < 128; c++) {
            if (cnt[c] > 0) chars.add(c);
        }

        chars.sort((a, b) -> Integer.compare(cnt[b], cnt[a]));
        
        StringBuilder sb = new StringBuilder();
        for (char c : chars) {
            for (int k = 0; k < cnt[c]; k++) {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}