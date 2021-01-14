/*
 * @lc app=leetcode id=166 lang=golang
 *
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (20.81%)
 * Likes:    705
 * Dislikes: 1558
 * Total Accepted:    112K
 * Total Submissions: 537.2K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * Example 1:
 * 
 * 
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * 
 * Example 3:
 * 
 * 
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 * 
 * 
 */

// @lc code=start
func fractionToDecimal(numerator int, denominator int) string {
	var res string 

	if numerator * denominator < 0 {
		res = "-"
	}

	if numerator < 0 {
		numerator *= -1
	}

	if denominator < 0 {
		denominator *= -1
	}

	res += strconv.Itoa(numerator/denominator)
	if numerator % denominator == 0 {
		return res
	}

	r := []byte{'.'}
	t := make(map[int]int, 1024)
	
	i := 1
	for true {
		numerator %= denominator
		if numerator == 0 {
			return res + string(r)
		}

		if t[numerator] != 0 {
			break
		}

		t[numerator] = i

		numerator *= 10
		r = append(r, byte('0' + numerator / denominator))
		i++
	}

	res += string(r[:t[numerator]])
	res += "("
	res += string(r[t[numerator]:])
	res += ")"
	return res
}
// @lc code=end

