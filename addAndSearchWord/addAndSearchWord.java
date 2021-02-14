class TrieNode {
    public TrieNode() {
        children = new TrieNode[26];
        isWord = false;
    }
    public TrieNode[] children;
    public char val;
    public boolean isWord;
}

class WordDictionary {

    /** Initialize your data structure here. */
    TrieNode root;
    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode cur = root;
        for (char c : word.toCharArray()) {
            if (cur.children[c - 'a'] == null) {
                cur.children[c - 'a'] = new TrieNode();
            }
            cur = cur.children[c - 'a'];
        }
        cur.isWord = true;
    }
    
    public boolean search(String word) {
        return dfs(word.toCharArray(), 0, root);
    }
    
    public boolean dfs(char[] chs, int index, TrieNode curNode) {
        if (index == chs.length) {
            return curNode.isWord;
        }
        if (chs[index] != '.') {
            TrieNode next = curNode.children[chs[index] - 'a'];
            return next != null && dfs(chs, index + 1, next);
        } else {
            for (int i = 0; i < curNode.children.length; i++) {
                TrieNode next = curNode.children[i];
                if (next != null && dfs(chs, index + 1, next)) {
                    return true;
                }
            }
        }
        return false;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */