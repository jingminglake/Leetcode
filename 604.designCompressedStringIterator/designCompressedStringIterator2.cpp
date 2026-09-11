class StringIterator {
public:
    StringIterator(string compressedString) {
        s = compressedString;
        index = 0;
        cur = ' ';
        count = 0;
    }
    
    char next() {
        char res = ' ';
        if (hasNext()) {
            res = cur;
            count--;
        }
        return res;
    }
    
    bool hasNext() {
        while (index != s.length() && count == 0) {
            cur = s[index++];
            while (isdigit(s[index])) {
                count = s[index] - '0' + count * 10;
                index++;
            }
        }
        return count != 0;
    }
    char cur;
    int count;
    string s;
    int index;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
