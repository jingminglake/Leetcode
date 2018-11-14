class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<String>();
        if (digits == null || digits.length() == 0) {
            return res;
        }
        String[] digit2letters = new String[] {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        StringBuilder path = new StringBuilder();
        dfs(digits, path, 0, res, digit2letters);
        return res;
    }
    void dfs(String digits, StringBuilder path, int level, List<String> res, String[] digit2letters) {
        if (level == digits.length()) {
            res.add(path.toString());
            return;
        }
        String letters = digit2letters[digits.charAt(level) - '0'];
        if (letters.length() == 0)
            dfs(digits, path, level + 1, res, digit2letters);
        for (int i = 0; i < letters.length(); i++) {
            char c = letters.charAt(i);
            path.append(c);
            dfs(digits, path, level + 1, res, digit2letters);
            path.deleteCharAt(path.length() - 1);
        }
    }
}
