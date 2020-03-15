/*
 * @lc app=leetcode id=127 lang=golang
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (27.73%)
 * Likes:    2509
 * Dislikes: 1019
 * Total Accepted:    368.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
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
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
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
 * Output: 0
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
func ladderLength(beginWord string, endWord string, words []string) int {
	dict := make(map[string]bool, len(words))
	for i := 0; i < len(words); i++ {
		dict[words[i]] = true
	}

	delete(dict, beginWord)

	queue := make([]string, 0, len(words))

	var trans func(string) bool

	trans = func(word string) bool {
		bytes := []byte(word)
		for i := 0; i < len(bytes); i++ {
			diffLetter := bytes[i]
			
			for j := 0; j < 26; j++ {
				b := 'a' + byte(j)
				if b == diffLetter {
					continue
				}

				bytes[i] = b

				if dict[string(bytes)] {
					if string(bytes) == endWord {
						return true
					}

					queue = append(queue, string(bytes))
					delete(dict, string(bytes))
				}
			}
			bytes[i] = diffLetter
		}

		return false
	}

	queue = append(queue, beginWord)
	dist := 1
	for len(queue) > 0 {
		qLen := len(queue)

		for i := 0; i < qLen; i++ {
			word := queue[0]
			queue = queue[1:]

			if trans(word) {
				return dist + 1
			}
		}

		dist++
	}

	return 0
}
// @lc code=end

