/*
 * @lc app=leetcode id=164 lang=golang
 *
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (34.39%)
 * Likes:    705
 * Dislikes: 163
 * Total Accepted:    82.3K
 * Total Submissions: 239K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either
 * (3,6) or (6,9) has the maximum difference 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return 0.
 * 
 * Note:
 * 
 * 
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * Try to solve it in linear time/space.
 * 
 * 
 */

// @lc code=start
func maximumGap(nums []int) int {
	sort.Ints(nums)
	
	ret := 0
	for i := 1; i < len(nums); i++ {
		tmp := nums[i] - nums[i-1]
		if ret < tmp {
			ret = tmp
		}
	}

	return ret
}
// @lc code=end

