/*
 * @lc app=leetcode id=583 lang=java
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
    public int minDistance(String word1, String word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int result = 0;
        int dp[][] = new int[l1 + 1][l2 + 1];
        for (int i = 0; i < l1; i++)
            dp[i][0] = 0;
        for (int j = 0; j < l2; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1))
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                result = Math.max(result, dp[i][j]);
            }
        }
        int l = (l1 - result) + (l2 - result);
        return l;
    }
}
// @lc code=end
