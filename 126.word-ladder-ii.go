/*
 * @lc app=leetcode id=126 lang=golang
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (20.58%)
 * Likes:    1484
 * Dislikes: 218
 * Total Accepted:    162.5K
 * Total Submissions: 789.2K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: []
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
func findLadders(beginWord string, endWord string, wordList []string) [][]string {
    return rec(beginWord, endWord, wordList, 1000)
}

func rec(beginWord string, endWord string, wordList []string, jump int) [][]string {
    if beginWord == endWord {
		return [][]string{[]string{beginWord}}
	}

	var res [][]string

	if jump == 0 {
		return res
	}

	for i := 0; i < len(wordList); i++ {
		if beginWord == wordList[i] {
			wordList = append(wordList[:i], wordList[i+1:]...)
			i--
		}
	}

	for i := range beginWord {
		var match []string
		var other []string 
		for _, v := range wordList {
			if beginWord[:i] == v[:i] && beginWord[i+1:] == v[i+1:] {
				match = append(match, v)
			} else {
				other = append(other, v)
			}
		}

		for _, v := range match {
			r := rec(v, endWord, other, jump-1)
			if len(r) == 0 || len(r[0]) > jump {
				continue
			} else if len(r[0]) < jump {
				jump = len(r[0])
				res = [][]string{}
			}
			for j := range(r) {
				r[j] = append([]string{beginWord}, r[j]...)
			}
			res = append(res, r...)
		}
	}

	return res
}
// @lc code=end

