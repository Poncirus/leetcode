/*
 * @lc app=leetcode id=65 lang=golang
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (14.70%)
 * Likes:    607
 * Dislikes: 4233
 * Total Accepted:    152.6K
 * Total Submissions: 1M
 * Testcase Example:  '"0"'
 *
 * Validate if a given string can be interpreted as a decimal number.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one. However, here is a
 * list of characters that can be in a valid decimal number:
 * 
 * 
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 * 
 * 
 * Of course, the context of these characters also matters in the input.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button to reset your code definition.
 * 
 */

// @lc code=start
func isNumber(s string) bool {
	// 去掉首位的空格
	s = trim(s)

	// 判断是否是实数
	return isReal(s)
}

func isReal(s string) bool {
	if len(s) == 0 {
		return false
	}

	if s[0] == '-' || s[0] == '+' {
		return isNonnegReal(s[1:], false)
	}

	return isNonnegReal(s, false)
}

func isNonnegReal(s string, hasDot bool) bool {
	if len(s) == 0 {
		return false
	}

	for i, c := range s {
		switch {
		case '0' <= c && c <= '9':
			continue
		case c == '.':
			if hasDot {
				return false
			}

			if i == len(s)-1 && i != 0 {
				return true
			}

			if i+1 < len(s) && s[i+1] == 'e' {
				return i != 0 && isInteger(s[i+2:])
			}

			return isNonnegReal(s[i+1:], true)
		case c == 'e':
			if i == 0 {
				return false
			}
			return isInteger(s[i+1:])
		default:
			return false
		}
	}

	return true
}

func isInteger(s string) bool {
	if len(s) == 0 {
		return false
	}

	if s[0] == '-' || s[0] == '+' {
		return isNonnegativeInteger(s[1:])
	}

	return isNonnegativeInteger(s)
}

func isNonnegativeInteger(s string) bool {
	if len(s) == 0 {
		return false
	}

	for _, c := range s {
		if c < '0' || '9' < c {
			return false
		}
	}
	return true
}

func trim(s string) string {
	i := 0
	for i < len(s) && s[i] == ' ' {
		i++
	}

	j := len(s) - 1
	for i <= j && s[j] == ' ' {
		j--
	}

	return s[i : j+1]
}


// @lc code=end

