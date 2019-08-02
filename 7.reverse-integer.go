import "math"

/*
 * @lc app=leetcode id=7 lang=golang
 *
 * [7] Reverse Integer
 */
func reverse(x int) int {
	a := 0
	for ; x != 0; x /= 10 {
		a = a*10 + x%10
	}

	if a > math.MaxInt32 || a < math.MinInt32 {
		return 0
	}

	return a
}
