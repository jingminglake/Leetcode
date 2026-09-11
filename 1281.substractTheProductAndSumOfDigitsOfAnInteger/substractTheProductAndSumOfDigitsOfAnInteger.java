class Solution {
    public int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while (n != 0) {
            int m = n % 10;
            product *= m;
            sum += m;
            n = n / 10;
        }
        return product - sum;
    }
}
