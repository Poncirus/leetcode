/*
 * @lc app=leetcode id=132 lang=golang
 *
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (29.30%)
 * Likes:    867
 * Dislikes: 29
 * Total Accepted:    121.4K
 * Total Submissions: 413.7K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 * 
 * 
 */

// @lc code=start
func minCut(s string) int {
	n := len(s)
	if n == 0 {
		return 0
	}

	dp := make([]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = i - 1
	}

	for i := 0; i < n+1; i++ {
		for j := 0; 0 <= i-j && i+j < n && s[i-j] == s[i+j]; j++ {
			dp[i+j+1] = min(dp[i-j]+1, dp[i+j+1])
		}

		for j := 1; 0 <= i-j+1 && i+j < n && s[i-j+1] == s[i+j]; j++ {
			dp[i+j+1] = min(dp[i-j+1]+1, dp[i+j+1])
		}
	}

	return dp[n]
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

// @lc code=end

