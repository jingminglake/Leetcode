class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int left = 0, right = m * n - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int i = mid / n;
            int j = mid % n;
            if (matrix[i][j] < target) {
                left = mid;
            } else if (matrix[i][j] > target) {
                right = mid;
            } else {
                return true;
            }
        }
        if (matrix[left / n][left % n] == target || matrix[right / n][right % n] == target) return true;
        else return false;
    }
}
