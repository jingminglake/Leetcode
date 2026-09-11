class Solution {
    public int numberOfChild(int n, int k) {
        int remain = k % (2 * n - 2);
        if (remain < n - 1) return remain;
        else return 2 * (n - 1) - remain;
    }
}