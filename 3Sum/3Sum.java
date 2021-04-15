class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums.length < 3) return res;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int n1 = nums[i];
            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                int twoSum = nums[left] + nums[right];
                if (twoSum < -n1) {
                    left++;
                } else if (twoSum > -n1) {
                    right--;
                } else {
                    List<Integer> tuple = new ArrayList<>();
                    tuple.add(n1);
                    tuple.add(nums[left]);
                    tuple.add(nums[right]);
                    res.add(tuple);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
            while (i + 1 < nums.length - 2 && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
}
