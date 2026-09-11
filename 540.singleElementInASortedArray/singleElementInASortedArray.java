class Solution {
    public int singleNonDuplicate(int[] nums) {
        int len = nums.length;
        if (len == 1) return nums[0];
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ( (right - mid) % 2 == 0 ) {
                if (nums[mid] == nums[mid - 1]) {
                    right = mid;
                } else if (nums[mid] == nums[mid + 1]) {
                    left = mid;
                } else {
                    return nums[mid];
                }
            } else {
                if (nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                } else if (nums[mid] == nums[mid + 1]) {
                    right = mid - 1;
                } else {
                    return nums[mid];
                }
            }
            
        }
        return nums[left];
    }
}
