class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        int rightOne = -1, i = 0;
        while (N) {
            i++;
            if (N % 2 == 1) {
                if (rightOne != -1) {
                    res = max (res, i - rightOne);
                }
                rightOne = i;
            }
            N /= 2;
        }
        return res;
    }
};
