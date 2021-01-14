import (
	"math"
	"strings"
)

/*
 * @lc app=leetcode id=8 lang=golang
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
func myAtoi(str string) int {
	r := 0
	i := 0
	sign := 1

	str = strings.TrimSpace(str)
	if str == "" {
		return r
	}

	if str[i] == '-' {
		sign = -1
		i++
	} else if str[i] == '+' {
		i++
	}

	for ; i < len(str) && str[i] >= '0' && str[i] <= '9'; i++ {
		r *= 10
		r += int(str[i] - '0')

		if r > math.MaxInt32 {
			if sign == 1 {
				return math.MaxInt32
			} else {
				return math.MinInt32
			}
		}
	}

	return r * sign
}

// @lc code=end
