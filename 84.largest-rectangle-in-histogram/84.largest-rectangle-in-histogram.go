/*
 * @lc app=leetcode id=84 lang=golang
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (33.44%)
 * Likes:    2863
 * Dislikes: 70
 * Total Accepted:    225.1K
 * Total Submissions: 672.6K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */

// @lc code=start
func largestRectangleArea(heights []int) int {
	r := 0
    for i, v := range(heights) {
		h := v
		for j := i; j >= 0; j-- {
			if heights[j] < h {
				h = heights[j]
			}

			val := (i - j + 1) * h
			if val > r {
				r = val
			}
		}
	}

	return r
}
// @lc code=end

