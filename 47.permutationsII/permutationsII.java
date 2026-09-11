class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        boolean[] visited = new boolean[nums.length];
        List<Integer> path = new ArrayList<>();
        dfs(nums, res, visited, path, 0);
        return res;
    }
    
    public void dfs(int[] nums, List<List<Integer>> res, boolean[] visited, List<Integer> path, int index) {
        if (index == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                if (i != 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
                path.add(nums[i]);
                visited[i] = true;
                dfs(nums, res, visited, path, index + 1);
                visited[i] = false;
                path.remove(path.size() - 1);
            }
        }
    }
}
