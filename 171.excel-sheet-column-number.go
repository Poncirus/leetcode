/*
 * @lc app=leetcode id=171 lang=golang
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
func titleToNumber(s string) int {
	r := 0
	for _, v := range s {
		r *= 26
		r += int(v-'A') + 1
	}
	return r
}

// @lc code=end
