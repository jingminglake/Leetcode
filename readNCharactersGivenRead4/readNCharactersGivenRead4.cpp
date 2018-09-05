// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char buf4[4];
        bool eof = false;
        int index = 0;
        while (!eof && index < n) {
            int len = read4(buf4);
            if (len < 4) {
                eof = true;
            }
            int remain = n - index;
            int round_len = min (len, remain);
            for (int k = 0; k < round_len; k++)
                buf[index++] = buf4[k];
        }
        return index;
    }
};
