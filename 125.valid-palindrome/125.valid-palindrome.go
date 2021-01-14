import "strings"

/*
 * @lc app=leetcode id=125 lang=golang
 *
 * [125] Valid Palindrome
 */

// @lc code=start
func isPalindrome(s string) bool {
	i := 0
	j := len(s) - 1

	s = strings.ToLower(s)

	for i < j {
		for i < len(s) && !((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= '9' && s[i] >= '0')) {
			i++
		}

		for j >= 0 && !((s[j] <= 'z' && s[j] >= 'a') || (s[j] <= '9' && s[j] >= '0')) {
			j--
		}

		if (i < len(s) && j >= 0 && s[i] != s[j]) || (i >= len(s) && j >= 0) || (i < len(s) && j < 0) {
			return false
		}

		i++
		j--
	}

	return true
}

// @lc code=end
