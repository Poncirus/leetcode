/*
 * @lc app=leetcode id=10 lang=golang
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
func isMatch(s string, p string) bool {
	return match(s, p, 0, 0)
}

func match(s string, p string, i int, j int) bool {
	for i < len(s) {
		if j >= len(p) {
			return false
		}

		if j+1 < len(p) && p[j+1] == '*' {
			t := p[j]
			j += 2

			if match(s, p, i, j) {
				return true
			}

			for i < len(s) && (s[i] == t || t == '.') {
				i++
				if match(s, p, i, j) {
					return true
				}
			}

			return j == len(p) && i == len(s)
		}

		if i < len(s) && j < len(p) && (s[i] == p[j] || p[j] == '.') {
			i++
			j++
		} else {
			return false
		}
	}

	for j+1 < len(p) && p[j+1] == '*' {
		j += 2
	}

	return j == len(p)
}

// @lc code=end
