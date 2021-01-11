class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Set<Integer> visited = new HashSet<>();
        List<Integer> path = new ArrayList<>();
        dfs(nums, res, visited, path, 0);
        return res;
    }
    
    private void dfs(int[] nums, List<List<Integer>> res, Set<Integer> visited, List<Integer> path, int level) {
        if (level == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!visited.contains(nums[i])) {
                path.add(nums[i]);
                visited.add(nums[i]);
                dfs(nums, res, visited, path, level + 1);
                path.remove(path.size() - 1);
                visited.remove(nums[i]);
            }
        }
    }
}
