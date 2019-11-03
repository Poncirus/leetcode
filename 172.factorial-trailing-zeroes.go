/*
 * @lc app=leetcode id=172 lang=golang
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
func trailingZeroes(n int) int {
	i := 0
	f := 5
	for n/f != 0 {
		i += n / f
		f *= 5
	}

	return i
}

// @lc code=end
