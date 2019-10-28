/*
 * @lc app=leetcode id=121 lang=golang
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
func maxProfit(prices []int) int {
	m := 0
	t := 0
	for i := 1; i < len(prices); i++ {
		t += prices[i] - prices[i-1]
		if t < 0 {
			t = 0
		}
		if m < t {
			m = t
		}
	}
	return m
}

// @lc code=end
