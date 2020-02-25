/*
 * @lc app=leetcode id=68 lang=golang
 *
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (25.77%)
 * Likes:    545
 * Dislikes: 1356
 * Total Accepted:    121K
 * Total Submissions: 465.9K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * Given an array of words and a width maxWidth, format the text such that each
 * line has exactly maxWidth characters and is fully (left and right)
 * justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 * 
 * Note:
 * 
 * 
 * A word is defined as a character sequence consisting of non-space characters
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth.
 * The input array words contains at least one word.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * Output:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall
 * be",
 * because the last line must be left-justified instead of fully-justified.
 * ⁠            Note that the second line is also left-justified becase it
 * contains only one word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * Output:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 */

// @lc code=start
func fullJustify(words []string, maxWidth int) []string {
	var res []string
	var temp []string

	l := 0
	for _, v := range(words) {
		if l + len(temp) + len(v) <= maxWidth {
			temp = append(temp, v)
			l += len(v)
			continue
		}

		if len(temp) == 1 {
			for len(temp[0]) != maxWidth {
				temp[0] += " "
			}
			res = append(res, temp[0])

			l = len(v)
			temp = []string{v}
			continue
		}

		sp := (maxWidth - l) / (len(temp) - 1)
		exsp := (maxWidth - l) % (len(temp) - 1)

		s := temp[0]
		for i := 1; i < len(temp); i++ {
			for j := 0; j < sp; j++ {
				s += " "
			}

			if exsp > 0 {
				s += " "
				exsp--
			}
			s += temp[i]
		}

		res = append(res, s)

		l = len(v)
		temp = []string{v}
	}

	if len(temp) == 0 {
		return res
	}

	s := temp[0]
	for i := 1; i < len(temp); i++ {
		s += " " + temp[i]
	}

	for len(s) < maxWidth {
		s += " "
	}

	res = append(res, s)
	return res
}
// @lc code=end

