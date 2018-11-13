class Solution {
    public String solveEquation(String equation) {
        int[] left = evalExp(equation.split("=")[0]);
        int[] right = evalExp(equation.split("=")[1]);
        int[] res = new int[2];
        res[0] = left[0] - right[0];
        res[1] = right[1] - left[1];
        if (res[0] == 0 && res[1] == 0) return "Infinite solutions";
        if (res[0] == 0) return "No solution";
        return "x=" + res[1] / res[0];
    }
    public int[] evalExp(String exp) {
        String[] tokens = exp.split("(?=[-+])");
        int[] res = new int[2];
        for (String token : tokens) {
            if (token.equals("+x") || token.equals("x")) res[0] += 1;
            else if (token.equals("-x")) res[0] -= 1;
            else if (token.contains("x")) res[0] += Integer.parseInt(token.substring(0, token.indexOf("x")));
            else res[1] += Integer.parseInt(token);
        }
        return res;
    }
}
