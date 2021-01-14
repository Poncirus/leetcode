/*
 * @lc app=leetcode id=76 lang=golang
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (33.34%)
 * Likes:    3546
 * Dislikes: 252
 * Total Accepted:    335.1K
 * Total Submissions: 1M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */

// @lc code=start
func minWindow(s string, t string) string {
	have := [128]int{}
	need := [128]int{}
	for i := range t {
		need[t[i]]++
	}

	size, total := len(s), len(t)

	min := size + 1
	res := ""

	for i, j, count := 0, 0, 0; j < size; j++ {
		if have[s[j]] < need[s[j]] {
			count++
		}
		have[s[j]]++

		for i <= j && have[s[i]] > need[s[i]] {
			have[s[i]]--
			i++
		}

		width := j - i + 1
		if count == total && min > width {
			min = width
			res = s[i : j+1]
		}

	}

	return res
}
// @lc code=end

