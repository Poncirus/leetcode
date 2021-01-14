/*
 * @lc app=leetcode id=5 lang=golang
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
func longestPalindrome(s string) string {
	c := 0
	st, ed := 0, 0
	for i, _ := range s {
		if i+1 != len(s) && s[i+1] == s[i] {
			cn := 1
			for i-cn >= 0 && i+1+cn < len(s) && s[i-cn] == s[i+1+cn] {
				cn++
			}

			if c < cn*2 {
				c = cn * 2
				st, ed = i-cn+1, i+1+cn
			}
		}

		cn := 1
		for i-cn >= 0 && i+cn < len(s) && s[i-cn] == s[i+cn] {
			cn++
		}

		if c < cn*2-1 {
			c = cn*2 - 1
			st, ed = i-cn+1, i+cn
		}
	}

	return s[st:ed]
}

// @lc code=end
