/*
 * @lc app=leetcode id=219 lang=golang
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (36.83%)
 * Likes:    729
 * Dislikes: 885
 * Total Accepted:    249.4K
 * Total Submissions: 674.8K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
func containsNearbyDuplicate(nums []int, k int) bool {
	t := make(map[int]bool, k + 1)
	for i := range nums {
		if t[nums[i]] {
			return true
		}
		
		t[nums[i]] = true

		if i >= k {
			delete(t, nums[i-k])
		}
	}

	return false
}
// @lc code=end

