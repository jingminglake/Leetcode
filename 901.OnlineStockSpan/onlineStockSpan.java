class StockSpanner {

    private Stack<Integer> idxStk;
    private List<Integer> stocks;
    public StockSpanner() {
        idxStk = new Stack<>(); // 0(100) -> 1(80) -> 2(60)
        stocks = new ArrayList<>();
    }
    
    public int next(int price) {
        int res = 0;
        stocks.add(price);
        int index = stocks.size() - 1;
        while (!idxStk.isEmpty() && price >= stocks.get(idxStk.peek())) {
            idxStk.pop();
        }

        if (!idxStk.isEmpty()) res = index - idxStk.peek();
        else res = index + 1;

        idxStk.push(index);

        return res;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */

 /*
 -1:
 0: 100 --> 1
 1: 80  --> 1
 2: 60  --> 1
 3: 70 --> 3 - 1
 4: 60 --> 1
 5: 75 --> 5 - 1

  */