class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        double[][] workers = new double[quality.length][2];
        for (int i = 0; i < quality.length; i++) {
            workers[i] = new double[]{(double) (wage[i]) / quality[i], (double) quality[i]};
        }
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        PriorityQueue<Double> pq = new PriorityQueue<>((a, b) -> Double.compare(b, a));
        double res = Double.MAX_VALUE, qsum = 0;
        for (int i = 0; i < workers.length; i++) {
            double[] worker = workers[i];
            if (i < k - 1) { // put k - 1 worker into pq at first
              qsum += worker[1];
              pq.add(worker[1]);
            } else {
                qsum += worker[1];
                res = Math.min(res, (qsum * worker[0]));
                pq.add(worker[1]);
                qsum -= pq.poll();
            }
        }
        return res;
    }
}
