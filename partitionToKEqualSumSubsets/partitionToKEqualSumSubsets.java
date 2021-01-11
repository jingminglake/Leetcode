class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        if (nums.length == 0) return false;
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % k != 0) return false;
        int target = sum / k;
        Arrays.sort(nums);
        boolean[] visited = new boolean[nums.length];
        return dfs(nums, k, visited, target, 0, 0);
    }
    boolean dfs(int[] nums, int k, boolean[] visited, int target, int path, int index) {
        //System.out.println(path);
        if (k == 1 && path == target) return true;
        if (k > 1 && path == target) {
            return dfs(nums, k - 1, visited, target, 0, 0); // index from 0 again!
        }
        for (int i = index; i < nums.length; i++) {
            if (visited[i]) continue;
            if (path + nums[i] > target) return false;
            if (i > index && nums[i] == nums[i - 1] && !visited[i - 1]) continue; // be careful: i - 1 maybe a visited one!
            // choose this element
            visited[i] = true;
            path += nums[i];
            if (dfs(nums, k, visited, target, path, i + 1)) return true;
            path -= nums[i];
            visited[i] = false;
        }
        return false;
    }
}