class Solution {
    public int countDays(int days, int[][] meetings) {
        int res = 0;
        int mLen = meetings.length;
        int[][] compressMeetings = new int[mLen][2];
        for (int i = 0; i < mLen; i++) {
            for (int j = 0; j < 2; j++) {
                compressMeetings[i][j] = meetings[i][j];
            }
        }
        Arrays.sort(compressMeetings, (a, b) -> Integer.compare(a[0], b[0]));
        int last = 0, i = 0;
        int j = 0;
        while (j < mLen) {
            if (compressMeetings[j][0] > compressMeetings[last][1]) {
                last++;
                compressMeetings[last][0] = compressMeetings[j][0];
                compressMeetings[last][1] = compressMeetings[j][1];
                j++;
            } else {
                compressMeetings[last][1] = Math.max(compressMeetings[last][1], compressMeetings[j][1]);
                j++;
            }
        }
        return countDayHelper(compressMeetings, days, last);
    }

    private int countDayHelper(int[][] compressMeetings, int days, int lastIndex) {
        int res = 0;
        //for (int i = 0; i < lastIndex; i++) {
        //     System.out.println(compressMeetings[i][0] + ", " + compressMeetings[i][1]);
        //}
        res += days - compressMeetings[lastIndex][1] + compressMeetings[0][0] - 1;
        for (int i = 1; i <= lastIndex; i++) {
            //System.out.println(compressMeetings[i][0] + ", " + compressMeetings[i][1]);
            res += compressMeetings[i][0] - compressMeetings[i - 1][1] - 1;
        }
        return res;
    }
}