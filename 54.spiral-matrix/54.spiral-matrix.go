/*
 * @lc app=leetcode id=54 lang=golang
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (32.58%)
 * Likes:    1781
 * Dislikes: 495
 * Total Accepted:    315.2K
 * Total Submissions: 964.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */

// @lc code=start
func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 {
		return []int{}
	}

	var res []int
	
	c := len(matrix) - 1
	r := len(matrix[0])
	i, j := -1, 0
	di, dj := 1, 1

	if r == 0 {
		return []int{}
	}

	for true {
		if r == 0 {
			break
		}

		for t := 0; t < r; t++ {
			i += di
			res = append(res, matrix[j][i])
		}

		if c == 0 {
			break
		}

		for t := 0; t < c; t++ {
			j += dj
			res = append(res, matrix[j][i])
		}

		r--
		c--
		di, dj = -di, -dj
	}

	return res
}
// @lc code=end

