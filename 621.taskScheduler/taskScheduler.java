class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] cnt = new int[26];
        for (char t : tasks) cnt[t - 'A']++;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int c : cnt) {
            if (c > 0) {
                pq.add(c);
            }
        }

        // element: {count, next available execute time}
        Queue<int[]> cooldown = new ArrayDeque<>();

        int time = 0;

        while (!pq.isEmpty() || !cooldown.isEmpty()) {
            while (!cooldown.isEmpty()) {
                if (cooldown.peek()[1] <= time) {
                    int[] readyTask = cooldown.poll();
                    pq.add(readyTask[0]);
                } else {
                    break;
                }
            }

            // update cooldown queue
            if (!pq.isEmpty()) {
                int remaining = pq.poll() - 1;
                // still remaining, then queue
                if (remaining > 0) {
                    cooldown.add(new int[] {remaining, time + n + 1});
                }
            }

            time++;
        }
        return time;
    }
}