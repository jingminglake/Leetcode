class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int res = 0;
        Arrays.sort(arr2);
        for (int n : arr1) {
            int lb = findLowerBound(arr2, n - d);
            int ub = findUpperBound(arr2, n + d);
            //System.out.println(lb + " " + ub);
            if (ub == lb) res++;
        }
        return res;
    }
    
    private int findLowerBound(int[] arr2, int target) {
        int len = arr2.length;
        if (len == 1) {
            if (arr2[0] >= target) return 0;
            else return -1;
        }
        int left = 0, right = len - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (arr2[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (arr2[left] >= target) return left;
        else if (arr2[right] >= target) return right;
        else return -1;
    }
    
    private int findUpperBound(int[] arr2, int target) {
        int len = arr2.length;
        if (len == 1) {
            if (arr2[0] > target) return 0;
            else return -1;
        }
        int left = 0, right = len - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (arr2[mid] <= target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (arr2[left] > target) return left;
        else if (arr2[right] > target) return right;
        else return -1;
    }
}
