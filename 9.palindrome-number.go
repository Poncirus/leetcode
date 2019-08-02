/*
 * @lc app=leetcode id=9 lang=golang
 *
 * [9] Palindrome Number
 */
func isPalindrome(x int) bool {
	if x == 0 {
		return true
	}

	if x < 0 || x%10 == 0 {
		return false
	}

	for r := 0; r <= x; x /= 10 {
		if r == x {
			return true
		}
		r = r*10 + x%10
		if r == x {
			return true
		}
	}
	return false
}
