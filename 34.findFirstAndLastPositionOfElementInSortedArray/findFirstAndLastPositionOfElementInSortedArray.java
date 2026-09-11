class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[] {-1, -1};
        if (nums.length == 0) return res;
        if (nums.length == 1) {
            if (nums[0] == target) {
                res = new int[] {0, 0};
            }
            return res;
        }
        res[0] = findFirstEqual(nums, target);
        res[1] = findLastEqual(nums, target);
        return res;
    }
    
    public int findFirstEqual(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (nums[left] == target) return left;
        else if (nums[right] == target) return right;
        else return -1;
    }
    
    public int findLastEqual(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (nums[right] == target) return right;
        else if (nums[left] == target) return left;
        else return -1;
    }
}
