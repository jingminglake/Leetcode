class Solution {
    public int nthUglyNumber(int n) {
        int[] uglys = new int[n];
        uglys[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            int min2 = uglys[p2] * 2;
            int min3 = uglys[p3] * 3;
            int min5 = uglys[p5] * 5;
            int ugly = Math.min(min2, Math.min(min3, min5));
            uglys[i] = ugly;
            if (min2 == ugly) p2++;
            if (min3 == ugly) p3++;
            if (min5 == ugly) p5++; 
        }
        return uglys[n - 1];
    }
}
