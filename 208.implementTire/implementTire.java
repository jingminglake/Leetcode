class Trie {
    Node root;
    public Trie() {
        root = new Node(' ');
    }

    public void insert(String word) {
        Node pCur = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (pCur.children[c - 'a'] == null)
                pCur.children[c - 'a'] = new Node(c);
            pCur = pCur.children[c - 'a'];
        }
        pCur.isWord = true;
    }

    public boolean search(String word) {
        Node pCur = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (pCur.children[c - 'a'] == null)
                return false;
            pCur = pCur.children[c - 'a'];
        }
        return pCur.isWord;
    }

    public boolean startsWith(String prefix) {
        // find the search root node
        Node pCur = root;
        for (int i = 0; i < prefix.length(); i++) {
            char c = prefix.charAt(i);
            if (pCur.children[c - 'a'] == null)
                return false;
            pCur = pCur.children[c - 'a'];
        }
        return true;
    }
}

class Node {
    char cur;
    Node[] children; // 26 children
    boolean isWord;
    Node(char cur) {
        this.cur = cur;
        this.children = new Node[26];
        this.isWord = false;
    }
    Node(char cur, boolean isWord) {
        this.cur = cur;
        this.children = new Node[26];
        this.isWord = isWord;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */