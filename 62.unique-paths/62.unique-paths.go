/*
 * @lc app=leetcode id=62 lang=golang
 *
 * [62] Unique Paths
 */

// @lc code=start
func uniquePaths(m int, n int) int {
	t := 1

	if m < n {
		m, n = n, m
	}

	for i := 0; i != n-1; i++ {
		t *= m + n - 2 - i
	}
	for i := 0; i != n-1; i++ {
		t /= i + 1
	}
	return t
}

// @lc code=end
