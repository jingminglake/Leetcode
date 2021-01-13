class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        Arrays.sort(candidates);
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
                if (i > index && candidates[i] == candidates[i - 1]) continue;
                path.add(candidates[i]);
                dfs (candidates, target - candidates[i], res, path, i + 1);
                path.remove(path.size() - 1);
            }
        }
    }
}
