/*
 * @lc app=leetcode id=205 lang=golang
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (39.08%)
 * Likes:    1136
 * Dislikes: 319
 * Total Accepted:    267.5K
 * Total Submissions: 683.7K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */

// @lc code=start
func isIsomorphic(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	
	m := make(map[byte]byte)
	
	for i := range s {
		v, ok := m[s[i]]
		if ok && v != t[i] {
			return false
		}

		if !ok {
			for j := 0; j < i; j++ {
				if t[j] == t[i] {
					return false
				}
			}
			m[s[i]] = t[i]
		}
	}

	return true
}
// @lc code=end

