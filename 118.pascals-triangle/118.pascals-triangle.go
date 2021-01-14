/*
 * @lc app=leetcode id=118 lang=golang
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
func generate(numRows int) [][]int {
	var r [][]int
	for i := 0; i != numRows; i++ {
		l := make([]int, i+1)
		l[0], l[i] = 1, 1

		for j := 1; j < i; j++ {
			l[j] = r[i-1][j-1] + r[i-1][j]
		}

		r = append(r, l)
	}

	return r
}

// @lc code=end
