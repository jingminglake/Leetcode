class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> res = new ArrayList<>();
        if (arr.length == 1) { 
            res.add(arr[0]);
            return res;
        }
        int left = 0, right = arr.length - k;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= x) {
                right = mid;
            } else if (arr[mid + k - 1] <= x) {
                left = mid;
            } else if (x - arr[mid] > arr[mid + k - 1] - x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        int resIndex = Math.abs(arr[left] - x) <= Math.abs(arr[right + k - 1] - x) ? left : right;
        for (int i = resIndex; i < resIndex + k; i++)
            res.add(arr[i]);
        return res;
    }
}
