class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        dfs(res, path, nums, 0);
        return res;
    }
    
    void dfs(List<List<Integer>> res, List<Integer> path, int[] nums, int index) {
        res.add(new ArrayList<>(path));
        for (int i = index; i < nums.length; i++) {
            path.add(nums[i]);
            dfs(res, path, nums, i + 1);
            path.remove(path.size() - 1);
        }
    }
}
