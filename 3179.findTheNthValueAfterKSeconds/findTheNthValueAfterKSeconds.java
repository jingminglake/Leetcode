class Solution {
    public int valueAfterKSeconds(int n, int k) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = 1;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) {
                    arr[j] += arr[j - 1];
                    arr[j] %= 1000000007;
                }
            }
        }
        return (int) (arr[n - 1] % 1000000007);
    }
}