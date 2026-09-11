class Solution {
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        Map<String, List<String>> transMap = new HashMap<>();
        for (String s : allowed) {
            String key = s.substring(0, 2);
            if (!transMap.containsKey(key)) {
                transMap.put(key, new ArrayList<String>());
            }
            transMap.get(key).add(s.substring(2));
        }
        return dfs(bottom, transMap);
    }
    
    public boolean dfs(String bottom, Map<String, List<String>> transMap) {
        if (bottom.length() == 1) return true;
        for (int i = 0; i < bottom.length() - 1; i++) {
            if (!transMap.containsKey(bottom.substring(i, i + 2))) return false;
        }
        Set<String> nextSet = new HashSet<>();
        getNext(bottom, transMap, new StringBuilder(), nextSet, 0);
        for(String s : nextSet) {
            if (dfs(s, transMap)) return true;
        }
        return false;
    }
    
    private void getNext(String bottom, Map<String, List<String>> transMap, StringBuilder sb, Set<String> res, int index) {
       if (index == bottom.length() - 1) {
           res.add(sb.toString());
           return;
       }
       for (String s : transMap.get(bottom.substring(index, index + 2))) {
           sb.append(s);
           getNext(bottom, transMap, sb, res, index + 1);
           sb.deleteCharAt(sb.length() - 1);
       }
    }
}
