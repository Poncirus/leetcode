/*
 * @lc app=leetcode id=209 lang=golang
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (36.78%)
 * Likes:    1802
 * Dislikes: 95
 * Total Accepted:    233.5K
 * Total Submissions: 633.6K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */

// @lc code=start
func minSubArrayLen(s int, nums []int) int {
	i, j := 0, 0
	sum := 0
	l := len(nums)

	for j < len(nums) {
		for j < len(nums) && sum < s {
			sum += nums[j]
			j++
		}

		if sum < s {
			if i == 0 {
				return 0
			}
			break
		}

		for sum >= s {
			sum -= nums[i]
			i++
		}
		
		if l > j - i + 1 {
			l = j - i + 1
		}
	}

	return l
}
// @lc code=end

