/*
 * @lc app=leetcode id=162 lang=golang
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (42.62%)
 * Likes:    1345
 * Dislikes: 1793
 * Total Accepted:    316K
 * Total Submissions: 740.9K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 * 
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 * 
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 * 
 * You may imagine that nums[-1] = nums[n] = -∞.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5 
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2, 
 * or index number 5 where the peak element is 6.
 * 
 * 
 * Note:
 * 
 * Your solution should be in logarithmic complexity.
 * 
 */

// @lc code=start
func findPeakElement(nums []int) int {
	low := -1
	high := len(nums)
	mid := (low + high) / 2

	for high - low > 2 {
		if nums[mid] < nums[mid+1] {
			low = mid
		} else {
			high = mid + 1
		}

		mid = (low + high) / 2
	}

	return mid
}
// @lc code=end

