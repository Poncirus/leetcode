import (
	"sort"
	"strings"
)

/*
 * @lc app=leetcode id=30 lang=golang
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (24.00%)
 * Likes:    662
 * Dislikes: 1041
 * Total Accepted:    151.5K
 * Total Submissions: 622.1K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 *
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 *
 *
 */

// @lc code=start
func findSubstring(s string, words []string) []int {
	sort.Strings(words)
	return reRange(s, "", words)
}

func reRange(s string, sub string, words []string) []int {
	if len(words) == 0 {
		if sub == "" {
			return []int{}
		}

		return findS(s, sub)
	}

	var r []int
	var t string
	for i, v := range words {
		if t == v {
			continue
		}
		t = v
		t := make([]string, len(words))
		copy(t, words)
		p := append(t[:i], t[i+1:]...)
		subr := reRange(s, sub+v, p)
		r = append(r, subr...)
	}

	return r
}

func findS(s string, word string) []int {
	var r []int
	p := 0
	for true {
		i := strings.Index(s, word)
		if i == -1 {
			return r
		}

		s = s[i+1:]
		r = append(r, p+i)
		p += i + 1
	}

	return r
}

// @lc code=end
