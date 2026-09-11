class Solution {
    public boolean canCross(int[] stones) {
        Map<Integer, Set<Integer>> dp = new HashMap<>();
        for (int stone : stones) {
            dp.put(stone, new HashSet<>());
        }
        dp.get(0).add(0);

        for (int s : stones) {
            for (int k : dp.get(s)) {
                if (k - 1 > 0 && dp.containsKey(s + k - 1))
                    dp.get(s + k - 1).add(k - 1);
                if (dp.containsKey(s + k))
                    dp.get(s + k).add(k);
                if (dp.containsKey(s + k + 1))
                    dp.get(s + k + 1).add(k + 1);
            }
        }

        return !dp.get(stones[stones.length - 1]).isEmpty();
    }
}
