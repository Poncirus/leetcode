/*
 * @lc app=leetcode id=56 lang=golang
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (37.81%)
 * Likes:    3253
 * Dislikes: 249
 * Total Accepted:    500K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
func merge(its [][]int) [][]int {
	if len(its) <= 1 {
		return its
	}

	sort.Slice(its, func(i int, j int) bool {
		return its[i][0] < its[j][0]
	})

	res := make([][]int, 0, len(its))

	temp := its[0]
	for i := 1; i < len(its); i++ {
		if its[i][0] <= temp[1] {
			temp[1] = max(temp[1], its[i][1])
		} else {
			res = append(res, temp)
			temp = its[i]
		}
	}
	res = append(res, temp)

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end

