class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        // sort first, for dedup
        Arrays.sort(candidates);
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
            // // same layer: skip duplicates after the first (i > startIndex); next layer may reuse the same value ([1,2,2])
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
            if (target < candidates[i]) continue;
            path.add(candidates[i]);
            dfs(candidates, target - candidates[i], res, path, i + 1);
            path.remove(path.size() - 1);
        }
    }
}
/*
[2,5,2,1,2], target = 5
sort -> [1,2,2,2,5]

dfs(target: 5, path: {}, startIndex: 0)
   i = 0, dfs(target: 5 - 1, path: {1}, startIndex: 1)
          i = 1, target:4 < candidates[1]=2? false, dfs(target: 4 - 2, path: {1, 2}, startIndex: 1+1 = 2);
                                                i = 2, i > startIndex:2? false, 2 < candidate[i]? false dfs(target: 2 - 2, path: {1, 2, 2}, startIndex:2+1= 3)
                                                    target = 0, res.add({1,2,2})
                                                i = 3, continue
                                                i = 4, continue
          i = 2, 2 > statIndex:1 && 2 == 2, continue
          i = 3, 2 > statIndex:1 && 2 == 2, continue
          i = 4, target:4 < 5, continue
   i = 1, dfs(target: 5 - 2, path: {2}, startIndex: 2)
          i = 2, target:3 < candidate[i]=2 false dfs(target: 3 - 2, path: {2, 2}, startIndex: 2+1=3)
                       i = 3, target:1 < candidate[i]=2, true, continue
                       i = 4, continue
          i = 3, continue
          i = 4, continue
   i = 2, i > startIndex:0 && 2 == 2, continue
   i = 3, i > startIndex:0 && 2 == 2, continue
   i = 4, target: 5 < candiates[4]=5 ? false, dfs(target: 0, path:{5}, startIndex: 4+1=5)
                                  target = 0, res.add({5})

return res: {[1,2,2],  [5]}
*/