/*
 * @lc app=leetcode id=20 lang=golang
 *
 * [20] Valid Parentheses
 */
func isValid(s string) bool {
	l := make([]byte, len(s))
	n := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '(' || s[i] == '{' || s[i] == '[' {
			l[n] = s[i]
			n++
		}

		if s[i] == ')' || s[i] == '}' || s[i] == ']' {
			if n--; n < 0 {
				return false
			}

			if l[n] == '(' && s[i] == ')' {
				continue
			}
			if l[n] == '[' && s[i] == ']' {
				continue
			}
			if l[n] == '{' && s[i] == '}' {
				continue
			}

			return false
		}
	}

	return n == 0
}
