/*
 * @lc app=leetcode id=169 lang=golang
 *
 * [169] Majority Element
 */

// @lc code=start
func majorityElement(nums []int) int {
	for _, i := range nums {
		t := 0
		for _, j := range nums {
			if i == j {
				t++
			}
		}
		if t > len(nums)/2 {
			return i
		}
	}

	return 0
}

// @lc code=end
