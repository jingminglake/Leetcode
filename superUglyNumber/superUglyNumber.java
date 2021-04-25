class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] uglys = new int[n];
        uglys[0] = 1;
        int len = primes.length;
        int[] uglyIndex = new int[len];
        PriorityQueue<Pair> pq = new PriorityQueue<>((p1, p2) -> p1.candidate - p2.candidate);
        for (int j = 0; j < primes.length; j++) {
            pq.add(new Pair(j, uglys[uglyIndex[j]++] * primes[j]));
        }
        for (int i = 1; i < n; i++) {
            Pair p = pq.poll();
            uglys[i] = p.candidate;
            pq.add(new Pair(p.primeIndex, uglys[uglyIndex[p.primeIndex]++] * primes[p.primeIndex]));
            
            while (pq.peek().candidate == uglys[i]) {
                p = pq.poll();
                pq.add(new Pair(p.primeIndex, uglys[uglyIndex[p.primeIndex]++] * primes[p.primeIndex]));
            }
        }
        return uglys[n - 1];
    }
    
    private class Pair {
        int primeIndex;
        int candidate;

        public Pair(int primeIndex, int candidate) {
            this.primeIndex = primeIndex;
            this.candidate = candidate;
        }
    }
}
