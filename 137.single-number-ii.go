/*
 * @lc app=leetcode id=137 lang=golang
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (48.61%)
 * Likes:    1230
 * Dislikes: 307
 * Total Accepted:    198.2K
 * Total Submissions: 407.3K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 */

// @lc code=start
func singleNumber(nums []int) int {
	/*
	t 1 2
	1 0 0
	1 1 0
	1 0 1
	1 0 0
	*/

	ones, twos := 0, 0
	for i := 0; i < len(nums); i++ {
		ones = (ones ^ nums[i]) & ^twos
		twos = (twos ^ nums[i]) & ^ones
	}
	return ones
}
// @lc code=end

