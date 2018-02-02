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
        bool eof = false;
        char read4Buf[4];
        int res = 0;
        while (!eof && res < n) {
            int count = read4(read4Buf);
            eof = count < 4;
            count = min (count, n - res);
            for (int i = 0; i < count; i++)
                buf[res++] = read4Buf[i];
        }
        return res;
    }
};
