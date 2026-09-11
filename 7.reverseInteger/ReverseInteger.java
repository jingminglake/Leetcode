import java.util.*;

class ReverseInteger {
    public int reverse(int x) {
        int flag = 1;
        long n = x;
        if (n < 0) {
            flag = -1;
            n = -n;
        }
        long res = 0;
        while (n != 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        res *= flag;
        return res > Integer.MAX_VALUE || res < Integer.MIN_VALUE ? 0 : (int) res;
    }
	public static void main(String[] args) {
		ReverseInteger s = new ReverseInteger();
		int x = -123;
		System.out.println(x + "\n" + s.reverse(x));
	}
}
