/*
 * @lc app=leetcode id=136 lang=golang
 *
 * [136] Single Number
 */

// @lc code=start
func singleNumber(nums []int) int {
	m := 0
	for _, v := range nums {
		m ^= v
	}

	return m
}

// @lc code=end
