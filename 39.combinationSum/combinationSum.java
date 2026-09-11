class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        dfs(candidates, target, res, path, 0);
        return res;
    }
    
    private void dfs(int[] candidates, int target, List<List<Integer>> res, List<Integer> path, int index) {
        //System.out.println(index + ", " + path);
        if (target == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = index; i < candidates.length; i++) {
            if (target >= candidates[i]) {
                path.add(candidates[i]);
                dfs (candidates, target - candidates[i], res, path, i);
                path.remove(path.size() - 1);
            }
        }
    }
}
