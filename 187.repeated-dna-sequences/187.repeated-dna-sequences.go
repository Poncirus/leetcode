/*
 * @lc app=leetcode id=187 lang=golang
 *
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (37.87%)
 * Likes:    619
 * Dislikes: 236
 * Total Accepted:    149.4K
 * Total Submissions: 394K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 * 
 * Example:
 * 
 * 
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 * 
 */

// @lc code=start
func findRepeatedDnaSequences(s string) []string {
    var res []string
	if len(s) <= 10 {
		return nil
	}

	rec := make(map[string]int, len(s)-9)
	for i := 0; i+10 <= len(s); i++ {
		str := s[i : i+10]
		if v := rec[str]; v == 1 {
			res = append(res, str)
		}
		rec[str]++
	}

	sort.Strings(res)

	return res
}
// @lc code=end

