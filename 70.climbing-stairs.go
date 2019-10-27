/*
 * @lc app=leetcode id=70 lang=golang
 *
 * [70] Climbing Stairs
 */

// @lc code=start
func climbStairs(n int) int {
	if n == 1 {
		return 1
	}

	r := make([]int, 3)

	r[0] = 1
	r[1] = 1
	p := 1

	for i := 2; i <= n; i++ {
		p++
		if p == 3 {
			p = 0
		}
		r[p] = 0
		r[p] = r[0] + r[1] + r[2]
	}

	return r[p]
}

// @lc code=end
