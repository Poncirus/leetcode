/*
 * @lc app=leetcode id=202 lang=golang
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (48.66%)
 * Likes:    1493
 * Dislikes: 342
 * Total Accepted:    336.2K
 * Total Submissions: 689.9K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 */

// @lc code=start
func isHappy(n int) bool {
	t := make(map[int]bool, 128)
	
	for n != 1 && t[n] == false {
		t[n] = true

		p := 0
		for n > 0 {
			p += (n%10)* (n%10)
			n /= 10
		}
		n = p
	}

	return n == 1
}
// @lc code=end

