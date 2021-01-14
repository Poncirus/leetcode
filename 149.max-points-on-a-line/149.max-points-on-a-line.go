/*
 * @lc app=leetcode id=149 lang=golang
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (16.63%)
 * Likes:    720
 * Dislikes: 1751
 * Total Accepted:    145K
 * Total Submissions: 870.8K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,2],[3,3]]
 * Output: 3
 * Explanation:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * Explanation:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
func maxPoints(points [][]int) int {
	if len(points) == 0 {
		return 0
	}

	s := 1
	for ; s < len(points); s++ {
		if points[1][0] != points[s][0] || points[1][1] != points[s][1] {
			break
		}
	}
	if s == len(points) {
		return s
	}

	res := 1
    for i := 0; i < len(points) - 1; i++ {
		for j := i + 1; j < len(points); j++ {
			if points[i][0] == points[j][0] && points[i][1] == points[j][1] {
				continue
			}

			count := 0

			for _, v := range points {
				if sameLine(points[i], points[j], v) {
					count++
				}
			}

			if res < count {
				res = count
			}
		}
	}

	return res
}

func sameLine(x, y, z []int) bool {
	return (z[0] - x[0]) * (y[1] - x[1]) == (z[1] - x[1]) * (y[0] - x[0])
}
// @lc code=end

