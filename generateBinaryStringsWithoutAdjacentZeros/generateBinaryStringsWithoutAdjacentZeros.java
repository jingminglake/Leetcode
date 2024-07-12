class Solution {
    public List<String> validStrings(int n) {
        List<String> res = new ArrayList<>();
        StringBuilder path = new StringBuilder();
        dfs(res, path, 0, '1', n);
        return res;
    }

    private void dfs(List<String> res, StringBuilder path, int index, char prev, int n) {
        if (index == n) {
            res.add(path.toString());
            return;
        }

        if (prev == '0') {
            path.append("1");
            dfs(res, path, index + 1, '1', n);
            path.deleteCharAt(path.length() - 1);
        } else {
            path.append('0');
            dfs(res, path, index + 1, '0', n);
            path.deleteCharAt(path.length() - 1);

            path.append('1');
            dfs(res, path, index + 1, '1', n);
            path.deleteCharAt(path.length() - 1);
        }
    }
}