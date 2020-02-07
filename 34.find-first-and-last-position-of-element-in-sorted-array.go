/*
 * @lc app=leetcode id=34 lang=golang
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.98%)
 * Likes:    2504
 * Dislikes: 114
 * Total Accepted:    412.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */

// @lc code=start
func searchRange(nums []int, target int) []int {
	if len(nums) == 0 {
		return []int{-1, -1}
	}

	m := len(nums) / 2
	if nums[m] == target {
		a, b := m, m

		for a-1 >= 0 && nums[a-1] == target {
			a--
		}

		for b+1 < len(nums) && nums[b+1] == target {
			b++
		}

		return []int{a, b}
	}

	if nums[m] < target {
		a := searchRange(nums[m+1:], target)
		if a[0] == -1 {
			return a
		}
		return []int{a[0] + m + 1, a[1] + m + 1}
	}

	if nums[m] > target {
		return searchRange(nums[:m], target)
	}

	return []int{-1, -1}
}

// @lc code=end
