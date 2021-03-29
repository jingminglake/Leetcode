class Solution {
    public double myPow(double x, int n) {
        long N = n;
        if (N == 0) return 1;
        if (N < 0) {
            N = -N;
            x = 1 / x;
        }
        double res = myPow(x * x, (int)(N / 2)); 
        if (N % 2 == 0) {
            return res;
        } else {
            return res * x;
        }
    }
}
