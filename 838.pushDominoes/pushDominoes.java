class Solution {
    public String pushDominoes(String dominoes) {
        String d = 'L' + dominoes + 'R';
        int N = d.length();
        int left = 0, right = 1;
        StringBuilder sb = new StringBuilder();
        while (right < N) {
            if (d.charAt(right) == '.') {
                right++;
                continue;
            }
            int dotNum = right - left - 1;
            if (d.charAt(right) == 'L') {
                if (d.charAt(left) == 'L') { // L...L
                    if (left != 0) sb.append('L');
                    for (int i = 0; i < dotNum; i++) sb.append('L');
                } else if (d.charAt(left) == 'R') { // R...L
                    sb.append('R');
                    for (int i = 0; i < dotNum / 2; i++) sb.append('R');
                    if (dotNum % 2 != 0) sb.append('.');
                    for (int i = 0; i < dotNum / 2; i++) sb.append('L');
                }
            } else if (d.charAt(right) == 'R') {
                if (d.charAt(left) == 'L') { // L...R
                    if (left != 0) sb.append('L');
                    for (int i = 0; i < dotNum; i++) sb.append('.');
                } else if (d.charAt(right) == 'R') { // R...R
                    for (int i = 0; i < dotNum + 1; i++) sb.append('R');
                }
            }
            left = right;
            right = left + 1;
        }
        return sb.toString();
    }
}
