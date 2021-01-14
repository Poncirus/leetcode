/*
 * @lc app=leetcode id=220 lang=golang
 *
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (20.50%)
 * Likes:    929
 * Dislikes: 970
 * Total Accepted:    114.8K
 * Total Submissions: 557.8K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the absolute difference between nums[i] and
 * nums[j] is at most t and the absolute difference between i and j is at most
 * k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 * 
 * 
 * 
 * 
 */

// @lc code=start
func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
    for i := 1; i < len(nums); i++ {
		for j := i - 1; j >= 0 && j >= i - k; j-- {
			if nums[i] - nums[j] >= -t && nums[i] - nums[j] <= t {
				return true
			}
		}
	}

	return false
}
// @lc code=end

