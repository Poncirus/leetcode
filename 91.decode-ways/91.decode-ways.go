/*
 * @lc app=leetcode id=91 lang=golang
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.73%)
 * Likes:    1862
 * Dislikes: 2116
 * Total Accepted:    316.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 *
 * Example 1:
 *
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 *
 */

// @lc code=start
func numDecodings(s string) int {
	dp := make([]int, len(s)+1)

	dp[0] = 1
	if s[0] != '0' {
		dp[1] = 1
	} else {
		dp[1] = 0
	}

	for i := 2; i <= len(s); i++ {
		dp[i] = 0
		if s[i-1] != '0' {
			dp[i] += dp[i-1]
		}

		if s[i-2] != '0' && (s[i-2] < '2' || (s[i-2] == '2' && s[i-1] < '7')) {
			dp[i] += dp[i-2]
		}
	}

	return dp[len(s)]
}

// @lc code=end
