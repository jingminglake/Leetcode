class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return res;
        }
        Arrays.sort(nums);
        List<Integer> path = new ArrayList<Integer>();
        dfs(nums, res, path, 0);
        return res;
    }
    
    private void dfs(int[] nums, List<List<Integer>> res, List<Integer> path, int index) {
        res.add(new ArrayList<>(path));
        for (int i = index; i < nums.length; i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            path.add(nums[i]);
            dfs(nums, res, path, i + 1);
            path.remove(path.size() - 1);
        }
    }
}
