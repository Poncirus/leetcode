/*
 * @lc app=leetcode id=120 lang=golang
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (42.42%)
 * Likes:    1605
 * Dislikes: 190
 * Total Accepted:    224.2K
 * Total Submissions: 528.5K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */

// @lc code=start
func minimumTotal(triangle [][]int) int {
    for i := 1; i < len(triangle); i++ {
		triangle[i][0] += triangle[i-1][0]

		for j := 1; j < len(triangle[i])-1; j++ {
			if triangle[i-1][j-1] < triangle[i-1][j] {
				triangle[i][j] += triangle[i-1][j-1]
			} else {
				triangle[i][j] += triangle[i-1][j]
			}
		}

		triangle[i][len(triangle[i])-1] += triangle[i-1][len(triangle[i-1])-1]
	}

	min := triangle[len(triangle)-1][0]
	for i := 1; i < len(triangle); i++ {
		if min > triangle[len(triangle)-1][i] {
			min = triangle[len(triangle)-1][i]
		}
	}

	return min
}
// @lc code=end

