/*
 * @lc app=leetcode id=216 lang=golang
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (54.69%)
 * Likes:    889
 * Dislikes: 47
 * Total Accepted:    153.5K
 * Total Submissions: 279.3K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */

// @lc code=start
func combinationSum3(k int, n int) [][]int {
	
	var r func(k, n, s int) [][]int
	r = func(k, n, s int) [][]int {
		if k == 0 && n == 0 {
			return [][]int{[]int{}}
		}

		if (s + 1) * k > n {
			return [][]int{}
		}
		
		var res [][]int

		for s = s + 1; s < 10; s++ {
			a := r(k - 1, n - s, s)
			for i := range a {
				a[i] = append([]int{s}, a[i]...)
			}
			res = append(res, a...)
		}

		return res
	}

	return r(k, n, 0)
}
// @lc code=end

