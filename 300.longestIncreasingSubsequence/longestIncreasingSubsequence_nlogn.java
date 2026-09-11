class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 1) return 1;
        List<Integer> tails = new ArrayList<>();
        tails.add(nums[0]);
        for (int i = 1; i < nums.length; i++) {
            int index = findFirstGreaterOrEqualThan(tails, nums[i]);
            if (index == -1) {
                tails.add(nums[i]);
            } else {
                tails.set(index, nums[i]);
            }
        }
        return tails.size();
    }
    
    public int findFirstGreaterOrEqualThan(List<Integer> tails, int target) {
        int len = tails.size();
        int left = 0, right = len - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (tails.get(mid) <= target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (tails.get(left) >= target) return left;
        else if (tails.get(right) >= target) return right;
        else return -1;
    }
}
