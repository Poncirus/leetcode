/*
 * @lc app=leetcode id=69 lang=golang
 *
 * [69] Sqrt(x)
 */

// @lc code=start
func mySqrt(x int) int {
	r := 0
	for true {
		i := 1
		n := 0
		for true {
			if (r+i)*(r+i) <= x {
				i *= 2
				n++
			} else {
				r += i / 2
				break
			}
		}

		if n == 0 {
			return r
		}
	}

	return r
}

// @lc code=end
