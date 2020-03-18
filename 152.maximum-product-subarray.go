/*
 * @lc app=leetcode id=152 lang=golang
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.88%)
 * Likes:    3291
 * Dislikes: 138
 * Total Accepted:    292.8K
 * Total Submissions: 947K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */

// @lc code=start
func maxProduct(nums []int) int {
	res := nums[0]
    for i := 0; i < len(nums); i++ {
		t := 1
		for j:= i; j < len(nums); j++ {
			t *= nums[j]
			if t > res {
				res = t
			}
		}
	}

	return res
}
// @lc code=end

