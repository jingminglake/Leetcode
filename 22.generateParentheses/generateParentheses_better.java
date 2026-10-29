class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        StringBuilder path = new StringBuilder();
        dfs(n, n, path, res);
        return res;
    }

    private void dfs(int leftP, int rightP, StringBuilder path, List<String> res) {
        if (leftP == 0 && rightP == 0) {
            res.add(path.toString());
            return;
        }
        if (leftP > rightP) return;
        // build character at index
        if (leftP > 0) {
            // try add a '('
            path.append('(');
            dfs(leftP - 1, rightP, path, res);
            path.deleteCharAt(path.length() - 1);
            
        }
        if (rightP > 0) {
            // try add a ')'
            path.append(')');
            dfs(leftP, rightP - 1, path, res);
            path.deleteCharAt(path.length() - 1);
        }
    }

    /*
    n == 1
    leftP = 1, rightP = 1
        path: "(" + dfs(1, 0, 1)
                    leftP = 0, rightP = 1
                    path: "()" res" {"()"}

        path: ")"  leftP = 1 > rightP = 0 return;
    res: {"()"}


    n == 2
    dfs(2, 2)
       path: "(" + dfs(1, 2)
                   path: "((" + dfs(0, 2)
                                path: "(()" + dfs(0, 1)
                                              path: "(())" + dfs(0, 0) -> res.add "(())"
                   path: "()" + dfs(1, 1)
                                path: "()(" + dfs(0, 1)
                                              path: "()()" + dfs(0, 0) -> res.add "()()"
        path: ")" leftP = 2 > rightP = 1 =  -> return
    res:  {"(())", "()()"}                     
    */
}