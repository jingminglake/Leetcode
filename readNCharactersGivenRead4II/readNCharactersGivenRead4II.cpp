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
        count = 0;
        p = 0;
    }
    int read(char *buf, int n) {
        int index = 0;
        while (index < n) {
            if (p == 0)
                count = read4(temp);
            if (count == 0)
                break;
            while (index < n && p < count) 
                buf[index++] = temp[p++];
            if (p == count)
                p = 0;
        }
        return index;
    }
    int count;
    int p;
    char temp[4];
};
