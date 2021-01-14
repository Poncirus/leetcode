/*
 * @lc app=leetcode id=64 lang=golang
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (48.18%)
 * Likes:    1779
 * Dislikes: 45
 * Total Accepted:    279.5K
 * Total Submissions: 564.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 *
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 *
 *
 */

// @lc code=start
func minPathSum(grid [][]int) int {
	m := len(grid[0])
	n := len(grid)

	for i := 1; i < m; i++ {
		grid[0][i] += grid[0][i-1]
	}

	for i := 1; i < n; i++ {
		grid[i][0] += grid[i-1][0]
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			grid[j][i] += min(grid[j-1][i], grid[j][i-1])
		}
	}

	return grid[n-1][m-1]
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

// @lc code=end
