class Solution {
    public int hIndex(int[] citations) {
        int len = citations.length;
        if (len == 1) {
            if (citations[0] >= 1) return 1;
            else return 0;
        }
        int left = 0, right = len - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= len - mid) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (citations[left] >= len - left) return len - left;
        else if (citations[right] >= len - right) return len - right;
        else return 0;
     }
}
