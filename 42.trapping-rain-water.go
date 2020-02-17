/*
 * @lc app=leetcode id=42 lang=golang
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (46.60%)
 * Likes:    5566
 * Dislikes: 104
 * Total Accepted:    426.9K
 * Total Submissions: 914.1K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */

// @lc code=start
func trap(height []int) int {
	r := 0
	
	p := []int{}

	for i, v := range(height) {
		j := len(p) - 1
		h := 0
		for ; j >= 0; j-- {
			if height[p[j]] > v {
				r += (i - p[j] - 1) * (v - h)
				break
			}
			r += (i - p[j] - 1) * (height[p[j]] - h)
			h = height[p[j]]
		}

		p = p[:j+1]
		p = append(p, i)
	}

	return r
}
// @lc code=end

