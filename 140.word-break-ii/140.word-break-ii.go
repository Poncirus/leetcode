/*
 * @lc app=leetcode id=140 lang=golang
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (29.85%)
 * Likes:    1530
 * Dislikes: 331
 * Total Accepted:    204.8K
 * Total Submissions: 684.7K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */

// @lc code=start
func wordBreak(s string, wordDict []string) []string {
	table := make([][]string, len(s))
	
	for _, v := range wordDict {
		if len(s)-len(v) >=0 && s[len(s)-len(v):len(s)] == v {
			table[len(s)-len(v)] = append(table[len(s)-len(v)], v)
		}
	}

	for i := len(s)-1; i > 0; i-- {
		if len(table[i]) == 0 {
			continue
		}

		for _, v := range wordDict {
			if i-len(v) >=0 && s[i-len(v):i] == v {
				for _, w := range table[i] {
					table[i-len(v)] = append(table[i-len(v)], v + " " + w)
				}
			}
		}

		table = table[:i]
	}

	return table[0]
}
// @lc code=end

