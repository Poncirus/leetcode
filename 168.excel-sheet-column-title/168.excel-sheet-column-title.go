/*
 * @lc app=leetcode id=168 lang=golang
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
func convertToTitle(n int) string {
	var s string
	for ; n != 0; n = (n - 1) / 26 {
		s = string('A'+(n-1)%26) + s
	}

	return s
}

// @lc code=end
