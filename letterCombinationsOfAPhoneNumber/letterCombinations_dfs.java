class Solution {
    public List<String> letterCombinations(String digits) {
         List<String> res = new ArrayList<>();
        if (digits == null || digits.length() == 0) {
            return res;
        }
        String[] digit2letter = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        StringBuilder path = new StringBuilder();
        dfs(digits, digit2letter, res, path, 0);
        return res;
    }
    
    private void dfs(String digits, String[] digit2letter, List<String> res, StringBuilder path, int level) {
        if (level == digits.length()) {
            res.add(path.toString());
            return;
        }
        String letter = digit2letter[digits.charAt(level) - '0'];
        for (char c : letter.toCharArray()) {
            path.append(c);
            dfs(digits, digit2letter, res, path, level + 1);
            path.deleteCharAt(path.length() - 1);;
        }
    }
}
