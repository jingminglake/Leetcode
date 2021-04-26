class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int count = countSmallOrEqual(matrix, mid);
            if (count >= k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (countSmallOrEqual(matrix, left) >= k) return left; // maybe >= k!
        else return right;
    }
    
    private int countSmallOrEqual(int[][] matrix, int target) {
        int count = 0;
        int n = matrix.length;
        int i = 0, j = n - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] > target) {
                j--;
            } else {
                count += j + 1;
                i++;
            }
        }
        return count;
    }
}
