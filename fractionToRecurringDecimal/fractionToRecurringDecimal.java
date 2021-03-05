class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        StringBuilder res = new StringBuilder();
        
        // handle '+', '-'
        if ((numerator > 0) ^ (denominator > 0)) res.append("-");
        long N = Math.abs((long)numerator);
        long D = Math.abs((long)denominator);
        
        // handle integer case
        if (N % D == 0) { 
            res.append(N / D);
            return res.toString(); 
        }
        
        // handle left integer part
        long leftPart = 0;
        if (N > D) {
            leftPart = N / D;
            N = N % D;
        }
        res.append(leftPart).append(".");
      
        // handle right fractional part
        Map<Long, Integer> remainderM = new HashMap<>();
        long remainder = N;
        StringBuilder rightPart = new StringBuilder();
        int index = 0;
        while (remainder != 0) {
            if (remainderM.containsKey(remainder)) {
                rightPart.insert((int)remainderM.get(remainder), '(');
                rightPart.insert(index + 1, ')');
                //System.out.println(remainderM.get(remainder) + " " + index);
                break;
            }
            remainderM.put(remainder, index++);
            
            N *= 10;
            while (N < D) { 
                N *= 10;
                rightPart.append(0);
                index++;
            }
            rightPart.append(N / D);   
            remainder = N % D;
            N = remainder;
        }
        
        res.append(rightPart);
        return res.toString();
    }
}
