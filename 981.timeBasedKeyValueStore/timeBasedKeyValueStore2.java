class TimeMap {
    private static class TimeValue {
        int timestamp;
        String value;

        TimeValue(int timestamp, String value) {
            this.timestamp = timestamp;
            this.value = value;
        }
    }
    Map<String, List<TimeValue>> m;
    public TimeMap() {
        m = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        m.computeIfAbsent(key, x -> new ArrayList<>()).add(new TimeValue(timestamp, value));
    }
    
    public String get(String key, int timestamp) {
        if (!m.containsKey(key)) return "";
        List<TimeValue> pairs = m.get(key); 
        // All the timestamps timestamp of set are strictly increasing.
        int left = 0, right = pairs.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (pairs.get(mid).timestamp > timestamp) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right == -1 ? "" : pairs.get(right).value;
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */