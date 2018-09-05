// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    Solution() {
        len_t = 0;
        p = 0;
    }
    int read(char *buf, int n) {
        int index = 0;
        bool eof = false;
        while (!eof && index < n) {
            if (p == 0)
                len_t = read4(temp);
            if (len_t < 4)
                eof = true;
            while (index < n && p < len_t) 
                buf[index++] = temp[p++];
            if (p == len_t)
                p = 0;
        }
        return index;
    }
    int len_t;
    int p;
    char temp[4];
};
