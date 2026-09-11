class Solution {
    public int waysToReachStair(int k) {
        int res = 0;
        Map<Integer, Map<Integer, Map<Integer, Integer>>> dp = new HashMap<>();

        return dfs(dp, 1, 0, 1, k);
    }

    private int dfs(Map<Integer, Map<Integer, Map<Integer, Integer>>> dp, int i, int jump, int flag, int k) {
        // flag: -1 means previous step go to left; 1 means previous step go to right

        //System.out.println("visit" + i + " " + jump);
        if (dp.containsKey(i) && dp.get(i).containsKey(jump) && dp.get(i).get(jump).containsKey(flag))
            return dp.get(i).get(jump).get(flag);
        int res = 0;
        if (i == k) res++;

        if (flag != -1 && i - 1 >= 0) {
            res += dfs(dp, i - 1, jump, -1, k);
        }

        if (i + (int) Math.pow(2, jump) <= k + 1) {
            res += dfs(dp, i + (int) Math.pow(2, jump), jump + 1, 1, k);
        }
        dpHelper(dp, i, jump, flag, res);
        return res;
    }


    private void dpHelper(Map<Integer, Map<Integer, Map<Integer, Integer>>> dp, int i, int jump, int flag, int value) {
        if (!dp.containsKey(i)) dp.put(i, new HashMap<Integer, Map<Integer, Integer>>());
        if (!dp.get(i).containsKey(jump)) {
            Map<Integer, Map<Integer, Integer>> m = dp.get(i);
            m.put(jump, new HashMap<Integer, Integer>());
        }
        if (!dp.get(i).get(jump).containsKey(flag)) {
            Map<Integer, Integer> m = dp.get(i).get(jump);
            m.put(flag, 0);
        }
        Map<Integer, Integer> m1 = dp.get(i).get(jump);
        m1.put(flag, value);
        Map<Integer, Map<Integer, Integer>> m2 = dp.get(i);
        m2.put(jump, m1);
        dp.put(i, m2);
    }
}