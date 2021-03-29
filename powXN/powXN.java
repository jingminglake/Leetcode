class Solution {
    public double myPow(double x, int n) {
        long N = n;
        if (N == 0) return 1;
        if (N < 0) {
            N = -N;
            x = 1 / x;
        }
        double sub = myPow(x, (int)(N / 2)); 
        if (N % 2 == 0) {
            return sub * sub;
        } else {
            return sub * sub * x;
        }
    }
}
