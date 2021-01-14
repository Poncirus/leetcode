/*
 * @lc app=leetcode id=128 lang=golang
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (43.91%)
 * Likes:    2678
 * Dislikes: 152
 * Total Accepted:    266.7K
 * Total Submissions: 606.9K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */

// @lc code=start
func longestConsecutive(nums []int) int {
	if len(nums) <= 1 {
		return len(nums)
	}

	sort.Ints(nums)

	max, temp := 0, 1
	for i := 1; i < len(nums); i++ {
		if nums[i]-1 == nums[i-1] {
			temp++
		} else if nums[i] != nums[i-1] {
			temp = 1
		}
		if max < temp {
			max = temp
		}
	}

	return max
}
// @lc code=end

