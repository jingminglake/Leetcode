public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String s : strs) {
            int len = s.length();
            sb.append(len + "#" + s);
        }
        return sb.toString(); // [hello, world] => 5#hello5#world
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> res = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            int j = s.indexOf('#', i); // i = 0, j = 1
            int len = Integer.valueOf(s.substring(i, j)); // len = s.substring(0, 1) = 5
            String segment = s.substring(j + 1, j + len + 1); // seg = substring(2, 1+5+1)
            res.add(segment);
            i = j + len + 1;  // i = 1+5+1
        }
        return res;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));

/*
strs = ["abcdefghij", "x"]      ← 第一个字符串长度是 10
encode → "10#abcdefghij1#x"

i = 0, j = 2
len = s.substring(0,2) = 10
seg = s.substring(2+1, 2+10+1) = abcdefghij

i = j + len + 1 = 13


*/