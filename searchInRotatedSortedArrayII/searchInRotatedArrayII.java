class Solution {
    public boolean search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
                return true;
            if (nums[mid] > nums[right]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid;
                else
                    left = mid; 
            } else if (nums[mid] < nums[right]){
                if (nums[mid] < target && target <= nums[right])
                    left = mid;
                else 
                    right = mid;
            } else {
                right--;
            }
        }
        if (nums[left] == target || nums[right] == target)
            return true;
        else return false;
    }
}
