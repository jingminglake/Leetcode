class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        PriorityQueue<Tuple> pq = new PriorityQueue<>((t1, t2) -> t1.val - t2.val);
        for (int i = 0; i < m; i++) {
            pq.offer(new Tuple(i, 0, matrix[i][0]));
        }
        for (int i = 1; i < k; i++) {
            Tuple t = pq.poll();
            if (t.j + 1 >= n) continue;
            pq.offer(new Tuple(t.i, t.j + 1, matrix[t.i][t.j + 1]));
        }
        return pq.poll().val;
    }
}

class Tuple {
    public int i, j, val;
    public Tuple(int i, int j, int val) {
        this.i = i;
        this.j = j;
        this.val = val;
    }
}
