/*
 * @lc app=leetcode id=664 lang=java
 *
 * [664] Strange Printer
 *
 * https://leetcode.com/problems/strange-printer/description/
 *
 * algorithms
 * Hard (43.04%)
 * Likes:    669
 * Dislikes: 59
 * Total Accepted:    20.2K
 * Total Submissions: 46.8K
 * Testcase Example:  '"aaabbb"'
 *
 * There is a strange printer with the following two special properties:
 * 
 * 
 * The printer can only print a sequence of the same character each time.
 * At each turn, the printer can print new characters starting from and ending
 * at any place and will cover the original existing characters.
 * 
 * 
 * Given a string s, return the minimum number of turns the printer needed to
 * print it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aaabbb"
 * Output: 2F
 * Explanation: Print "aaa" first and then print "bbb".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aba"
 * Output: 2
 * Explanation: Print "aaa" first and then print "b" from the second place of
 * the string, which will cover the existing character 'a'.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int strangePrinter(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int n = s.length();
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i < n - 1) {
                dp[i][i + 1] = s.charAt(i) == s.charAt(i + 1) ? 1 : 2;
            }
        }

        for (int len = 2; len < n; len++) {
            for (int start = 0; start + len < n; start++) {
                dp[start][start + len] = len + 1;
                for (int k = 0; k < len; k++) {
                    int temp = dp[start][start + k] + dp[start + k + 1][start + len];
                    dp[start][start + len] = Math.min(dp[start][start + len],
                            s.charAt(start + k) == s.charAt(start + len) ? temp - 1 : temp);
                }
            }
        }

        return dp[0][n - 1];
    }
}
// @lc code=end
