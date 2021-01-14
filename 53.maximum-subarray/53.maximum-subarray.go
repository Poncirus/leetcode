/*
 * @lc app=leetcode id=53 lang=golang
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.28%)
 * Likes:    4861
 * Dislikes: 183
 * Total Accepted:    600K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */
func maxSubArray(nums []int) int {
	r := nums[0]
	t := nums[0]

	for i := 1; i < len(nums); i++ {
		t += nums[i]

		if nums[i] > t {
			t = nums[i]
		}

		if t > r {
			r = t
		}
	}

	return r
}
