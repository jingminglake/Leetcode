class StringIterator {
public:
    StringIterator(string compressedString) {
        index = 0;
        s = compressedString;
        c = ' ';
        cnt = 0;
    }
    
    char next() {
        if (!hasNext())
            return ' ';
        cnt--;
        return c;
    }
    
    bool hasNext() {
        if (cnt == 0) {
            if (index >= s.length())
                return false;
            c = s[index];
            index++;
            while (isdigit(s[index])) {
                cnt = cnt * 10 + s[index] - '0';
                index++;
            }
        }
        return true;
    }
    int index;
    string s;
    char c;
    int cnt;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
