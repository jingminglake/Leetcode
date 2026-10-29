class StockSpanner {

    Stack<int[]> idxStk;  // {index, val}
    int index;
    public StockSpanner() {
        idxStk = new Stack<>();
        index = -1;
    }
    
    public int next(int price) {
        index++;

        // strictly make sure there are no equal or less prices in the stack
        while (!idxStk.isEmpty() && idxStk.peek()[1] <= price) {  
                idxStk.pop();
        }
        int size = idxStk.size();
        int res = (size == 0 ? index + 1 : index - idxStk.peek()[0]);

        idxStk.push(new int[]{index, price});
        return res;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);


100 -> 0 - (-1) = 1    stk: 0(100)
80 -> 1 - 0 = 1        stk: 0(100), 1(80)
60 -> 2 - 1 = 1        stk: 0(100), 1(80), 2(60)
70 -> 3 - 1 = 2        stk: 0(100), 1(80), 3(70)
60 -> 4 - 3 = 1        stk: 0(100), 1(80), 3(70), 4(60)
75 -> 5 - 1 = 4        stk: 0(100), 1(80), 5(75)
85 -> 6 - 0 = 6        stk: 0(100), 6(85)

5 -> 0 - (-1) = 1  stk: 0(5)
5 -> 1 - (-1) = 2  stk: 1(5)
5 -> 2 - (-1) = 3  stk: 2(5)
5 -> 3 - (-1) = 4  stk: 3(5)
3 -> 4 - 3 = 1  stk: 3(5), 4(1) 

 */