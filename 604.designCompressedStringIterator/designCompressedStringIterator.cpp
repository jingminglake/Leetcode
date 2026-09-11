class StringIterator {
public:
    StringIterator(string compressedString) {
        int i = 0;
        while (i < compressedString.length()) {
            if (compressedString[i] < '0' || compressedString[i] > '9') {
                vec.push_back(compressedString[i]);
                i++;
            }
            long num = 0;
            while (i < compressedString.length() && compressedString[i] >= '0' && compressedString[i] <= '9') {
                num *= 10;
                num += compressedString[i] - '0';
                i++;
            }
            vec.push_back(num);
        }
        reverse(vec.begin(), vec.end());
    }
    
    char next() {
        char res = ' ';
        if (hasNext()) {
            res = vec.back();
            vec.pop_back();
            --vec.back();
            if (vec.back() == 0) {
                vec.pop_back();
            } else if (vec.back() > 0){
                vec.push_back(res);
            }
        }
        return res;
    }
    
    bool hasNext() {
        return !vec.empty();
    }
    vector<long> vec;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
