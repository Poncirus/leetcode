/*
 * @lc app=leetcode id=79 lang=golang
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (33.66%)
 * Likes:    2814
 * Dislikes: 144
 * Total Accepted:    394.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */

// @lc code=start
func exist(board [][]byte, word string) bool {
    for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if board[i][j] == word[0] && e(board, word[1:], i, j) {
				return true
			}
		}
	}

	return false
}

func e(board [][]byte, word string, i, j int) bool {
	if len(word) == 0 {
		return true
	}
	
	t := board[i][j]
	board[i][j] = 0

	if i - 1 >= 0 && board[i-1][j] == word[0] && e(board, word[1:], i-1, j) {
		return true
	}

	if i + 1 < len(board) && board[i+1][j] == word[0] && e(board, word[1:], i+1, j) {
		return true
	}

	if j - 1 >= 0 && board[i][j-1] == word[0] && e(board, word[1:], i, j-1) {
		return true
	}

	if j + 1 < len(board[0]) && board[i][j+1] == word[0] && e(board, word[1:], i, j+1) {
		return true
	}

	board[i][j] = t
	return false
}
// @lc code=end

