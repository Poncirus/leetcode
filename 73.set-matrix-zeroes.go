/*
 * @lc app=leetcode id=73 lang=golang
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (41.96%)
 * Likes:    1603
 * Dislikes: 270
 * Total Accepted:    273.3K
 * Total Submissions: 651.3K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */

// @lc code=start
func setZeroes(mat [][]int) {
	m, n := len(mat), len(mat[0])
	col0 := 1

	for i := 0; i < m; i++ {
		if mat[i][0] == 0 {
			col0 = 0
		}
		for j := 1; j < n; j++ {
			if mat[i][j] == 0 {
				mat[i][0] = 0
				mat[0][j] = 0
			}
		}
	}

	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 1; j-- {
			if mat[i][0] == 0 || mat[0][j] == 0 {
				mat[i][j] = 0
			}
		}
		if col0 == 0 {
			mat[i][0] = 0
		}
	}

}

// @lc code=end

