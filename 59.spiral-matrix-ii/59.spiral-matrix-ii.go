/*
 * @lc app=leetcode id=59 lang=golang
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (50.94%)
 * Likes:    771
 * Dislikes: 100
 * Total Accepted:    172.8K
 * Total Submissions: 337.5K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */

// @lc code=start
func generateMatrix(n int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = make([]int, n)
	}
	
	pp := 1
	c := n - 1
	r := n
	i, j := -1, 0
	di, dj := 1, 1

	for true {
		if r == 0 {
			break
		}

		for t := 0; t < r; t++ {
			i += di
			res[j][i] = pp
			pp++
		}

		if c == 0 {
			break
		}

		for t := 0; t < c; t++ {
			j += dj
			res[j][i] = pp
			pp++
		}

		r--
		c--
		di, dj = -di, -dj
	}

	return res
}

// @lc code=end

