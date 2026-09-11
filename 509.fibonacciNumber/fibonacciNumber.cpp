class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        int f0 = 0, f1 = 1;
        while (N-- > 1) {
            int sum = f0 + f1;
            f0 = f1;
            f1 = sum;
        }
        return f1;
    }
};
