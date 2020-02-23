/*
 * @lc app=leetcode id=55 lang=golang
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (33.12%)
 * Likes:    3033
 * Dislikes: 271
 * Total Accepted:    362.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */

// @lc code=start
func canJump(nums []int) bool {
	p := 0
	
	for p + nums[p] < len(nums) - 1 {
		if nums[p] == 0 {
			return false
		}

		i, m := 1, 0
		for t := 1; t <= nums[p]; t++ {
			if nums[p+t] + t > m {
				m = nums[p+t] + t
				i = t
			}
		}

		p += i
	}

	return true
}
// @lc code=end

