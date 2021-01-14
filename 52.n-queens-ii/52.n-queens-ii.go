/*
 * @lc app=leetcode id=52 lang=golang
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (55.30%)
 * Likes:    388
 * Dislikes: 135
 * Total Accepted:    120.2K
 * Total Submissions: 216.6K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

// @lc code=start
func totalNQueens(n int) int {
	if n == 0 {
		return 0
	}

	cols := make([]bool, n)
	d1 := make([]bool, 2*n)
	d2 := make([]bool, 2*n)

	res := 0

	dfs(0, cols, d1, d2, &res)

	return res
}

func dfs(r int, cols, d1, d2 []bool, res *int) {
	n := len(cols)

	if r == n {
		*res++
		return
	}

	for c := 0; c < n; c++ {
		id1 := r - c + n
		id2 := 2*n - r - c - 1
		if !cols[c] && !d1[id1] && !d2[id2] {

			cols[c], d1[id1], d2[id2] = true, true, true

			dfs(r+1, cols, d1, d2, res)

			cols[c], d1[id1], d2[id2] = false, false, false
		}
	}
}
// @lc code=end

