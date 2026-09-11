class Solution {
    public long countCompleteDayPairs(int[] hours) {
        long res = 0;
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < hours.length; i++) {
            int hour = hours[i] % 24;
            res += countHelper(map, hour);
            if (!map.containsKey(hour)) {
                List<Integer> list = new ArrayList<>();
                map.put(hour, list);
            }
            map.get(hour).add(i);
        }
        return res;
    }

    private long countHelper(Map<Integer, List<Integer>> map, int hour) {
        long res = 0;
        if (hour == 0 && map.containsKey(0)) res += map.get(0).size();
        else if (map.containsKey(24 - hour)) res += map.get(24 - hour).size();
        return res;
    }
}