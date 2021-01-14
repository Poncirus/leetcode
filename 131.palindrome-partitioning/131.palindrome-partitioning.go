/*
 * @lc app=leetcode id=131 lang=golang
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (44.91%)
 * Likes:    1449
 * Dislikes: 55
 * Total Accepted:    205.2K
 * Total Submissions: 456.1K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */

// @lc code=start
func partition(s string) [][]string {
	result := [][]string{}
	current := make([]string, 0, len(s))
	dfs(s, 0, current, &result)
	return result
}

func dfs(s string, i int, cur []string, result *[][]string) {
	if i == len(s) {
		tmp := make([]string, len(cur))
		copy(tmp, cur)
		*result = append(*result, tmp)
		return
	}

	for j := i; j < len(s); j++ {
		if par(s[i : j+1]) {
			dfs(s, j+1, append(cur, s[i:j+1]), result)
		}
	}
}

func par(s string) bool {
	if len(s) <= 1 {
		return true
	}
	a, b := 0, len(s)-1
	for a < b {
		if s[a] != s[b] {
			return false
		}
		a++
		b--
	}
	return true
}

// @lc code=end

