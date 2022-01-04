class Solution {
    public boolean canCross(int[] stones) {
        Map<Integer, Set<Integer>> hm = new HashMap<>();
        for (int i = 0; i < stones.length; i++) hm.put(i, new HashSet<>()); // init
        hm.get(0).add(0);
        for (int i = 0; i < stones.length; i++) {
            for (int lastStep : hm.get(i)) {
                for (int j = i + 1; j < stones.length; j++) {
                    int gap = stones[j] - stones[i];
                    if (lastStep - 1 >= 0 && lastStep - 1 == gap) hm.get(j).add(lastStep - 1);
                    else if (lastStep == gap) hm.get(j).add(lastStep);
                    else if (lastStep + 1 == gap) hm.get(j).add(lastStep + 1);
                    else if (lastStep + 1 < gap) break;
                }
            }
        }
        return hm.get(stones.length - 1).size() >= 1;
    }
}
