/*
 * @lc app=leetcode id=214 lang=golang
 *
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (28.99%)
 * Likes:    967
 * Dislikes: 105
 * Total Accepted:    91.2K
 * Total Submissions: 313.5K
 * Testcase Example:  '"aacecaaa"'
 *
 * Given a string s, you are allowed to convert it to a palindrome by adding
 * characters in front of it. Find and return the shortest palindrome you can
 * find by performing this transformation.
 * 
 * Example 1:
 * 
 * 
 * Input: "aacecaaa"
 * Output: "aaacecaaa"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "abcd"
 * Output: "dcbabcd"
 */

// @lc code=start
func shortestPalindrome(s string) string {
	for i := (len(s)-1) / 2; i >= 0; i-- {
		j := 1
		for ; j <= i; j++ {
			if s[i-j] != s[i+j] {
				break
			}
		}

		if j > i {
			b := []byte(s)
			for i + j < len(s) {
				b = append([]byte{s[i+j]}, b...)
				j++
			}
	
			return string(b)
		}

		j = 0
		for ; j < i; j++ {
			if s[i-j-1] != s[i+j] {
				break
			}
		}

		if i == j {
			b := []byte(s)
			for i + j < len(s) {
				b = append([]byte{s[i+j]}, b...)
				j++
			}
	
			return string(b)
		}
	}

	return ""
}
// @lc code=end

