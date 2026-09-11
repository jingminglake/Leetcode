class Solution {
    public int magicalString(int n) {
        if (n <= 3) return 1;
        int pSeed = 2;
        StringBuilder sb = new StringBuilder();
        sb.append("122");
        int res = 1;
        while (sb.length() != n && sb.length() != n + 1) {
            if (sb.charAt(pSeed) == '1') { 
                if (sb.charAt(sb.length() - 1) == '2') {
                    sb.append("1");
                    res++;
                } else {
                    sb.append("2");
                }
            } else {
                if (sb.charAt(sb.length() - 1) == '2') {
                    sb.append("11");
                    res += 2;
                } else {
                    sb.append("22");
                }
            }
            pSeed++;
        }
        if (sb.length() == n + 1 && sb.charAt(sb.length() - 1) == '1') res--;
        return res;
    }
}
