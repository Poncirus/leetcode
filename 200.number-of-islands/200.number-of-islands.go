/*
 * @lc app=leetcode id=200 lang=golang
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (44.91%)
 * Likes:    4317
 * Dislikes: 158
 * Total Accepted:    571.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

// @lc code=start
func numIslands(grid [][]byte) int {
	res := 0
	
	var mark func(int, int)
	mark = func (i, j int) {
		grid[i][j] = '0'

		if j - 1 >= 0 && grid[i][j-1] != '0' {
			mark(i, j - 1)
		}

		if j + 1 < len(grid[i]) && grid[i][j+1] != '0' {
			mark(i, j + 1)
		}

		if i - 1 >= 0 && grid[i-1][j] != '0' {
			mark(i - 1, j)
		}
	
		if i + 1 < len(grid) && grid[i+1][j] != '0' {
			mark(i + 1, j)
		}
	}

	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] != '0' {
				res++
				mark(i, j)
			}
		}
	}

	return res
}
// @lc code=end

