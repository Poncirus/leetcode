/*
 * @lc app=leetcode id=212 lang=golang
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (32.15%)
 * Likes:    1862
 * Dislikes: 90
 * Total Accepted:    168.6K
 * Total Submissions: 522.9K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 
 * board = [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 * 
 * Output: ["eat","oath"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 * 
 * 
 */

// @lc code=start
func findWords(board [][]byte, words []string) []string {
    res := []string{}

    var find func(b [][]byte, word string, i, j int) bool
    find = func(b [][]byte, word string, i, j int) bool {
        if len(word) == 0 {
            return true
        }

        if i < 0 || i >= len(b) || j < 0 || j >= len(b[i]) {
            return false
        }

        if word[0] != b[i][j] {
            return false
        }

        t := b[i][j]
        b[i][j] = 0
        word = word[1:]
        res := find(b, word, i-1, j) || find(b, word, i+1, j) || find(b, word, i, j-1)|| find(b, word, i, j+1)
        b[i][j] = t
        return res
    }

    for i := range board {
        for j := range board[i] {
            for k, v := range words {
                if find(board, v, i, j) {
                    res = append(res, v)
                    words = append(words[:k], words[k+1:]...)
                }
            }
        }
    }

    return res
}
// @lc code=end

