/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> stk;
        stk.push(NestedInteger());
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '-' || isdigit(c)) {
                int sign = 1;
                int num = 0;
                if (c == '-') {
                    sign = -1;
                    c = s[++i];
                }
                while (i < s.length() && isdigit(c)) {
                    num = num * 10 + c - '0';
                    c = s[++i];
                }
                i--;
                stk.top().add(NestedInteger(sign * num));
            } else {
                if (c == '[') {
                    stk.push(NestedInteger());
                }
                else if (c == ']') {
                    NestedInteger ni = stk.top();
                    stk.pop();
                    stk.top().add(ni);
                }
            }
        } // for
        return stk.top().getList()[0];
    }
};
