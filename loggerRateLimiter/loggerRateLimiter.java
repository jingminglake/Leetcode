class Logger {

    /** Initialize your data structure here. */
    public Logger() {
        m = new HashMap<>();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if (m.containsKey(message) && m.get(message) + 10 > timestamp) {
            return false;
        }
        m.put(message, timestamp);
        return true;
    }
    Map<String, Integer> m;
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */
