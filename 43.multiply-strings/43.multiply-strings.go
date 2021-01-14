/*
 * @lc app=leetcode id=43 lang=golang
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (32.53%)
 * Likes:    1438
 * Dislikes: 662
 * Total Accepted:    256.5K
 * Total Submissions: 786.6K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
func multiply(num1 string, num2 string) string {
    if num1 == "0" || num2 == "0" {
		return "0"
	}

	t := make([]int, len(num1)+len(num2))

	for i := 0; i < len(num1); i++ {
		for j := 0; j < len(num2); j++ {
			t[i+j+1] += int(num1[i]-'0') * int(num2[j]-'0')
		}
	}

	for i := len(t)-1; i > 0; i-- {
		t[i-1] += t[i] / 10
		t[i] = t[i] % 10
	}

	if t[0] == 0 {
		t = t[1:]
	}

	r := make([]byte, len(t))
	for i, v := range(t) {
		r[i] = '0' + byte(v)
	}

	return string(r)
}
// @lc code=end

