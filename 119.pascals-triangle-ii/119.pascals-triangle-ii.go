/*
 * @lc app=leetcode id=119 lang=golang
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
func getRow(rowIndex int) []int {
	var r [][]int
	for i := 0; i <= rowIndex; i++ {
		l := make([]int, i+1)
		l[0], l[i] = 1, 1

		for j := 1; j < i; j++ {
			l[j] = r[i-1][j-1] + r[i-1][j]
		}

		r = append(r, l)
	}

	return r[rowIndex]
}

// @lc code=end
