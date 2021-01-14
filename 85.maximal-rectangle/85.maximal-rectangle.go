/*
 * @lc app=leetcode id=85 lang=golang
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (35.93%)
 * Likes:    2144
 * Dislikes: 57
 * Total Accepted:    154.1K
 * Total Submissions: 428.6K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */

// @lc code=start
func maximalRectangle(mat [][]byte) int {
	m := len(mat)
	if m == 0 {
		return 0
	}

	n := len(mat[0])
	if n == 0 {
		return 0
	}

	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
	}

	for j := 0; j < n; j++ {
		dp[0][j] = int(mat[0][j] - '0')
		for i := 1; i < m; i++ {
			if mat[i][j] == '1' {
				dp[i][j] = dp[i-1][j] + 1
			}
		}
	}

	max := 0
	for i := 0; i < m; i++ {
		tmp := largestRectangleArea(dp[i])
		if max < tmp {
			max = tmp
		}
	}

	return max
}

func largestRectangleArea(heights []int) int {
	h := append(heights, -1)
	n := len(h)

	var maxArea, height, left, right, area int
	var stack []int

	for right < n {
		if len(stack) == 0 || h[stack[len(stack)-1]] <= h[right] {
			stack = append(stack, right)
			right++
			continue
		}

		height = h[stack[len(stack)-1]]
		stack = stack[:len(stack)-1]

		if len(stack) == 0 {
			left = -1
		} else {
			left = stack[len(stack)-1]
		}

		area = (right - left - 1) * height
		if maxArea < area {
			maxArea = area
		}
	}

	return maxArea
}
// @lc code=end

