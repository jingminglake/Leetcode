class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int target = -nums[i];
            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                int sum2 = nums[left] + nums[right];
                if (sum2 < target) {
                    left++;
                } else if (sum2 > target) {
                    right--;
                } else {
                    List<Integer> triplet = new ArrayList<>();
                    triplet.add(nums[i]);
                    triplet.add(nums[left]);
                    triplet.add(nums[right]);
                    res.add(triplet);
                    left++;
                    right--;
                    if (left >= right) break;
                    // dedup 1
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (right > left && nums[right] == nums[right + 1]) right--;
                }
            }
            // dedup 2
            while (i + 1 < nums.length && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
}