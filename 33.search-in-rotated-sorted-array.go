/*
 * @lc app=leetcode id=33 lang=golang
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.55%)
 * Likes:    3567
 * Dislikes: 392
 * Total Accepted:    555K
 * Total Submissions: 1.7M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

// @lc code=start
func search(nums []int, target int) int {
	if len(nums) == 0 {
		return -1
	}

    if target < nums[0] {
		for i := len(nums)-1; i > 0 && (i == len(nums)-1 || nums[i] < nums[i+1]); i-- {
			if target == nums[i] {
				return i
			}

			if target > nums[i] {
				return -1
			}
		}

		return -1
	}

	for i := 0; i < len(nums) && (i == 0 || nums[i-1] < nums[i]); i++ {
		if target == nums[i] {
			return i
		}

		if target < nums[i] {
			return -1
		}
	}

	return -1
}
// @lc code=end

