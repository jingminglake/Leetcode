public class Solution {
    public int solve(ArrayList<ArrayList<Integer>> A) {
        Map<Integer, Integer> timeline = new TreeMap<>();
        for (int i = 0; i < A.size(); i++) {
            int start = A.get(i).get(0);
            if (timeline.containsKey(start)) {
                timeline.put(start, timeline.get(start) + 1);
            } else {
                timeline.put(start, 1);
            }
            
            int end = A.get(i).get(1);
            if (timeline.containsKey(end)) {
                timeline.put(end, timeline.get(end) - 1);
            } else {
                timeline.put(end, -1);
            }
            //System.out.println("Start = " + start + ", End = " + end);
        }
        int res = 0, ongoing = 0;
        for (Map.Entry<Integer, Integer> entry : timeline.entrySet()) {
           // System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue());
            res = Math.max(res, ongoing += entry.getValue());
        }
        //System.out.println(timeline.size());
        return res;
    }
}
