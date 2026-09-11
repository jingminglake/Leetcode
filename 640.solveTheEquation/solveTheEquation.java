class Solution {
    public String solveEquation(String equation) {
        if (equation == null || !equation.contains("=")) return "No solution";
        String[] part = equation.split("=");
        int[] leftRes = evalExp(part[0]);
        int[] rightRes = evalExp(part[1]);
        int[] res = new int[2];
        res[0] = leftRes[0] - rightRes[0];
        res[1] = rightRes[1] - leftRes[1];
        if (res[0] == 0 && res[1] == 0) return "Infinite solutions";
        if (res[0] == 0) return "No solution";
        return "x=" + res[1] / res[0];
    }
    
    private int[] evalExp(String exp) {
        int res[] = new int[2];
        if (exp == null) return res;
        String[] tokens = exp.split("(?=[-+])");
        for (String token : tokens) {
            //System.out.print(token + " ");
            if (token.equals("+x") || token.equals("x")) res[0]++;
            else if (token.equals("-x")) res[0]--;
            else if (token.contains("x")) res[0] += Integer.parseInt(token.substring(0, token.indexOf("x")));
            else res[1] += Integer.parseInt(token);
        }
        //System.out.println();
        return res;
    }
}
