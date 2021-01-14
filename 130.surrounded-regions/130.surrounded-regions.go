/*
 * @lc app=leetcode id=130 lang=golang
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (25.48%)
 * Likes:    1205
 * Dislikes: 549
 * Total Accepted:    188.9K
 * Total Submissions: 740.3K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

// @lc code=start
func solve(board [][]byte)  {
	if len(board) == 0 || len(board[0]) == 0 {
		return
	}

	var mark func(int, int)

	mark = func(i int, j int) {
		if i < 0 || i >= len(board) || j < 0 || j >= len(board[0]) {
			return
		}

		if board[i][j] != 'O' {
			return
		}

		board[i][j] = 'T'
		mark(i-1, j)
		mark(i+1, j)
		mark(i, j+1)
		mark(i, j-1)
	}

	for k := 0; k < len(board); k++ {
		if board[k][0] == 'O' {
			mark(k, 0)
		}

		if board[k][len(board[0])-1] == 'O' {
			mark(k, len(board[0])-1)
		}
	}

	for k := 1; k < len(board[0]) - 1; k++ {
		if board[0][k] == 'O' {
			mark(0, k)
		}

		if board[len(board)-1][k] == 'O' {
			mark(len(board)-1, k)
		}
	}

	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if board[i][j] == 'O' {
				board[i][j] = 'X'
			}

			if board[i][j] == 'T' {
				board[i][j] = 'O'
			}
		}
	}
}
// @lc code=end

