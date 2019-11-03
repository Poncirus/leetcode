import "strings"

/*
 * @lc app=leetcode id=6 lang=golang
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}

	var sb strings.Builder
	for i := 0; i < numRows; i++ {
		if i == 0 || i == numRows-1 {
			k := (numRows - 1) * 2
			for j := i; j < len(s); j += k {
				sb.WriteByte(s[j])
			}
		} else {
			k := (numRows - 1 - i) * 2
			p := i * 2
			j := i
			for true {
				if j >= len(s) {
					break
				}
				sb.WriteByte(s[j])
				j += k

				if j >= len(s) {
					break
				}
				sb.WriteByte(s[j])
				j += p
			}
		}
	}

	return sb.String()
}

// @lc code=end
