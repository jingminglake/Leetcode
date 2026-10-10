class Solution {
    public int getNumberOfBacklogOrders(int[][] orders) {
        final int MOD = 1_000_000_007;

        PriorityQueue<int[]> buy = new PriorityQueue<>((a, b) -> Integer.compare(b[0], a[0])); // {price, remainingAmout}
        PriorityQueue<int[]> sell = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0])); // {price, remainingAmout}

        for (int[] order : orders) {
            int price = order[0];
            int amount = order[1];
            int type = order[2];

            if (type == 0) { // buy
                // consume sell pq until not possible or buy amount == 0
                while (amount > 0 && !sell.isEmpty() && sell.peek()[0] <= price) {
                    int[] sellTop = sell.peek();
                    if (sellTop[1] < amount) {
                        sell.poll();
                        amount -= sellTop[1];
                    } else if (sellTop[1] > amount) {
                        sellTop[1] -= amount;
                        amount = 0;
                    } else {
                        amount = 0;
                        sell.poll();
                    }
                }
                // buy amount still > 0
                if (amount > 0) {
                    buy.offer(new int[]{price, amount});
                }
            } else { // sell 
                // consumer buy pq, until sell amount == 0 or pq is not available
                while (amount > 0 && !buy.isEmpty() && buy.peek()[0] >= price) {
                    int[] buyTop = buy.peek();
                    if (amount > buyTop[1]) {
                        amount -= buyTop[1];
                        buy.poll();
                    } else if (amount < buyTop[1]) {
                        buyTop[1] -= amount;
                        amount = 0;
                    } else {
                        amount = 0;
                        buy.poll();
                    }
                }
                // sell amount still > 0
                if (amount > 0) {
                    sell.offer(new int[]{price, amount});
                }
            }
        }

        long res = 0;
        while (!buy.isEmpty()) {
            int[] buyTop = buy.poll();
            res += buyTop[1];
        }
        while (!sell.isEmpty()) {
            int[] sellTop = sell.poll();
            res += sellTop[1];
        }
        return (int) (res % MOD);
    }
}