/*
 * @lc app=leetcode id=67 lang=golang
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (40.13%)
 * Likes:    1100
 * Dislikes: 210
 * Total Accepted:    328.4K
 * Total Submissions: 817.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 */
func addBinary(a string, b string) string {

	var s string

	i := len(a) - 1
	j := len(b) - 1

	t := 0

	for i >= 0 || j >= 0 {
		ai := 0
		bi := 0

		if i >= 0 && a[i] == '1' {
			ai = 1
		}

		if j >= 0 && b[j] == '1' {
			bi = 1
		}

		n := ai + bi + t
		if n == 3 {
			s = "1" + s
			t = 1
		} else if n == 2 {
			s = "0" + s
			t = 1
		} else if n == 1 {
			s = "1" + s
			t = 0
		} else {
			s = "0" + s
			t = 0
		}

		i--
		j--
	}

	if t == 1 {
		s = "1" + s
	}

	return s
}
