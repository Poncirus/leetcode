/*
 * @lc app=leetcode id=139 lang=golang
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (38.36%)
 * Likes:    3509
 * Dislikes: 192
 * Total Accepted:    474K
 * Total Submissions: 1.2M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
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
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */

// @lc code=start
func wordBreak(s string, wordDict []string) bool {
	long := 0
	for _, v := range wordDict {
		if len(v) > long {
			long = len(v)
		}
	}

	t := make([]bool, len(s))

	var r func(int) bool 
	
	r = func(pos int) bool {
		if pos == len(s) {
			return true
		}

		if t[pos] {
			return false
		}

		for i := 1; i <= long && pos + i <= len(s); i++ {
			for _, v := range wordDict {
				if s[pos:pos+i] == v && r(pos+i){
					return true
				}
			}
		}

		t[pos] = true
		return false
	}

	return r(0)
}
// @lc code=end

