import "math"

/*
 * @lc app=leetcode id=16 lang=golang
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.77%)
 * Likes:    1433
 * Dislikes: 105
 * Total Accepted:    394.9K
 * Total Submissions: 863.9K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 */

// @lc code=start
func threeSumClosest(nums []int, target int) int {
	s := nums[0] + nums[1] + nums[2]
	c := math.Abs(float64(s - target))

	for i := 0; i < len(nums)-2; i++ {
		for j := i + 1; j < len(nums)-1; j++ {
			for k := j + 1; k < len(nums); k++ {
				m := nums[i] + nums[j] + nums[k]
				if math.Abs(float64(m-target)) < c {
					s = m
					c = math.Abs(float64(m - target))
				}
			}
		}
	}

	return s
}

// @lc code=end
