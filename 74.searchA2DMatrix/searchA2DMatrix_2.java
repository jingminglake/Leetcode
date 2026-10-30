class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int left = 0, right = m * n - 1; // []
        // while window size > 0
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int x = mid / n;
            int y = mid % n;
            if (matrix[x][y] > target) {
                right = mid - 1;
            } else if (matrix[x][y] < target) {
                left = mid + 1;
            } else return true;
        }
        return false;
    }

    /*
    index = x * n + y -> x = (index - y) / n; y = index - x * n
    x = 1, y = 1, index = 5, m = 3, n = 4
    5 = 1 * 4 + 1. 

    ex: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    m = 3, n = 4
    left = 0, right = 11
    mid = 0 + 11/2 = 5, x = 5 / 4 = 1, y = 5 % 4 = 1, matrix[x][y] == 11 > target right = 5 - 1 = 4
    mid = 0 + 4/2 = 2, x = 0, y = 2, matrix[0][2] == 5 > target right = 2 - 1 = 1
    mid = 0 + 1/2 = 0, x = 0, y = 0, matrix[0][0] == 1 < target left = 0 + 1 = 1
    mid = 1, x = 0, y = 1, matrix[0][1] = 3 == target, return true

    ex2: [[1],[3]] target = 3
    m = 2, n = 1
    left = 0, right = 2 - 1 = 1
    mid = 0 + 1/2 = 0, x = 0, y = 0, matrix[0][0] == 1 < target left = 0 + 1 = 1
    mid = 1  + (1-1)/2 = 1, x = 1/1 = 1, y = 1 % 1 = 0, matrix[1][0] = 3 == 3 return true
    */
}