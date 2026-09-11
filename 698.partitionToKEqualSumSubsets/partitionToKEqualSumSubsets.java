class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % k != 0) return false;
        int target = sum / k;
        Arrays.sort(nums);
        boolean[] visited = new boolean[nums.length];
        return dfs(nums, k, target, 0, visited, 0);
    }
    
    public boolean dfs(int[] nums, int k, int target, int pathSum, boolean[] visited, int start) {
        if (target == pathSum) {
            if (k == 1) {
                return true;
            } else {
                return dfs(nums, k - 1, target, 0, visited, 0);
            }
        }
        for (int i = start; i < nums.length; i++) {
            if (target >= nums[i] + pathSum) {
                if (visited[i]) continue;
                if (i > start && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
                pathSum += nums[i];
                visited[i] = true;
                if (dfs(nums, k, target, pathSum, visited, i + 1)) {
                    return true;
                }
                pathSum -= nums[i];
                visited[i] = false;
            } else {
                return false;
            }
        }
        return false;
    }
}
