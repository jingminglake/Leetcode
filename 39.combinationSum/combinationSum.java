class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();

        dfs(candidates, target, res, path, 0);
        return res;
    }

    private void dfs(int[] candidates, int target, List<List<Integer>> res,  List<Integer> path, int startIndex) {
        if (target == 0) {
            res.add(new ArrayList<>(path)); // deep copy here
            return;
        }
        for (int i = startIndex; i < candidates.length; i++) {
            if (target < candidates[i]) continue;
            path.add(candidates[i]);
            dfs(candidates, target - candidates[i], res, path, i);
            path.remove(path.size() - 1);
        }
    }
}

/* [2,3,6,7], target = 7

dfs(target: 7, path:{}, startIndex: 0)
target = 7 == 0? false
    dfs(target: 7 - 2, path: {2}, startIndex: 0)
         dfs(target: 5 - 2, path: {2, 2}, startIndex: 0)
             i = 0 dfs(target: 3 - 2, path: {2, 2, 2}, startIndex: 0)
                target: 1 < 2 continue
             i = 1 dfs(target: 3 - 3, path: {2, 2, 3}, startIndex: 1)
                target = 0 --> res.add({2, 2, 3})
             target: 3 < 6 continue
             target: 3 < 7 continue
         dfs(target: 5 - 3, path: {2, 3}, startIndex: 1)
            target: 2 < candidates[1]=3 continue
         target: 5 < 6 continue
         target: 5 < 7 continue
    dfs(target: 7 - 3, path: {3}, startIndex: 1)
       dfs(target: 4 - 3, path: {3, 3}, startIndex: 1)
          target: 1 < 3 continue
       target:4 < 6 continue
       target: 4 < 7 continue
    dfs(target: 7 - 6, path: {6}, startIndex: 2)
       target: 1 < 6 continue
       target: 1 < 7 continue
    dfs(target: 7 - 7. path: {7}, startIndex: 3)
       target: 0 == 0, res.add({7})

return res= [{2, 2, 3}, {7}]


*/