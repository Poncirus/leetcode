/*
 * @lc app=leetcode id=204 lang=golang
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (30.66%)
 * Likes:    1631
 * Dislikes: 528
 * Total Accepted:    317.2K
 * Total Submissions: 1M
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */

// @lc code=start
func countPrimes(n int) int {
	if n < 3 {
		return 0
	}

	p := []int{2}

	for i := 3; i < n; i += 2 {
		for _, v := range p {
			if i % v == 0 {
				break
			}

			if v * v > i {
				p = append(p, i)
				break
			}
		}
	}
	
	return len(p)
}
// @lc code=end

