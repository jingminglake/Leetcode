class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int n = words.length;
        int start = 0;
        while (start < n) {
            // 1. 选出本行的单词范围 [start, end)
            int end = start;
            int letters = 0;
            int wordCnt = 0;
            while (end < n && letters + words[end].length() + wordCnt <= maxWidth) {
                letters += words[end].length();
                end++;
                wordCnt++;
            }

            // 构建这一行
            StringBuilder sb = new StringBuilder();
            if (end == n || wordCnt == 1) {
                // 最后一行或只有一个单词 -> 左对齐
                for (int i = start; i < end; i++) {
                    if (i > start) sb.append(' ');
                    sb.append(words[i]);
                }
                // 行尾补空格
                while (sb.length() < maxWidth) {
                    sb.append(' ');
                }
            } else {
                // 普通行，两端对齐
                int spaces = (maxWidth - letters) / (wordCnt - 1);
                int spaceLeft = (maxWidth - letters) % (wordCnt - 1);
                for (int i = start; i < end; i++) {
                    sb.append(words[i]);
                    if (i < end - 1) {
                        // 左边尝试多放一个空格
                        int cnt = spaces + (spaceLeft-- > 0 ? 1 : 0);
                        for (int k = 0; k < cnt; k++) {
                            sb.append(' ');
                        }
                    }
                }
            }

            res.add(sb.toString());
            start = end;
        }
        return res;
    }
}