/*
 * @lc app=leetcode id=564 lang=java
 *
 * [564] Find the Closest Palindrome
 */

// @lc code=start
class Solution {
    long res;
    long val;

    public String nearestPalindromic(String n) {
        val = Long.parseLong(n);
        res = 0;
        var len = n.length();

        // max number with one less digits
        var k = 0l;
        for (int i = 0; i < len - 1; i++) {
            k *= 10;
            k += 9;
        }
        helper(k);

        // keep left side and modify right side to make palindrome
        var chars = n.toCharArray();
        var l = 0;
        var r = chars.length - 1;
        while (l < r) {
            chars[r--] = chars[l++];
        }
        k = Long.parseLong(new String(chars));
        helper(k);

        var mid = (len - 1) / 2;
        var tmp = chars[mid];
        // modify mid digit(s) down
        if (tmp > '0') {
            chars[mid] = (char) (tmp - 1);
            if (len % 2 == 0) {
                chars[mid + 1] = chars[mid];
            }
            helper(chars);
        }

        // modify mid digit(s) up
        if (tmp < '9') {
            chars[mid] = (char) (tmp + 1);
            if (len % 2 == 0) {
                chars[mid + 1] = chars[mid];
            }
            helper(chars);
        }

        // min of number with one more digits
        k = 1l;
        for (int i = 0; i < len; i++) {
            k *= 10;
        }
        k += 1;
        helper(k);

        return "" + res;
    }

    void helper(char[] chars) {
        helper(Long.parseLong(new String(chars)));
    }

    void helper(long k) {
        if (Math.abs(val - k) == Math.abs(val - res) && k < res) {
            res = k;
        } else if (k != val && Math.abs(val - k) < Math.abs(val - res)) {
            res = k;
        }
    }
}
// @lc code=end
