/*
 * @lc app=leetcode id=45 lang=golang
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (29.61%)
 * Likes:    1880
 * Dislikes: 111
 * Total Accepted:    223K
 * Total Submissions: 751.9K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */

// @lc code=start
func jump(nums []int) int {
    t := make([]int, len(nums)) 
	t[0] = 0

	for i, v := range(nums) {
		for j := 1; j <= v; j++ {
			if i+j < len(nums) && (t[i+j] == 0 || t[i+j] > t[i]+1) {
				t[i+j] = t[i] + 1
			}
		}
	}

	return t[len(nums)-1]
}
// @lc code=end

