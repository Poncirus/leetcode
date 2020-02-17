/*
 * @lc app=leetcode id=41 lang=golang
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (30.67%)
 * Likes:    2591
 * Dislikes: 711
 * Total Accepted:    283K
 * Total Submissions: 921.2K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */

// @lc code=start
func firstMissingPositive(nums []int) int {
	num := make([]bool, len(nums) + 1)
	i := 1

	for _,v := range(nums) {
		if 0 < v && v < len(num) {
			num[v] = true
		}

		if v == i {
			for i < len(num) && num[i] {
				i++
			}
		}
	}

	return i
}
// @lc code=end

