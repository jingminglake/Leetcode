class Solution {
    public int numTimesAllBlue(int[] light) {
        int res = 0;
        int right = -1;
        for (int i = 0; i < light.length; i++) {
            right = Math.max(right, light[i]);
            if (i + 1 == right) { 
                res++;
            }
        }
        return res;
    }
}