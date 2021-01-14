/*
 * @lc app=leetcode id=77 lang=golang
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (52.05%)
 * Likes:    1171
 * Dislikes: 59
 * Total Accepted:    257.4K
 * Total Submissions: 494.4K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */

// @lc code=start
func combine(n int, k int) [][]int {
	if n < k {
		return [][]int{}
	}

	if k == 0 {
		return [][]int{[]int{}}
	}

	res := combine(n-1, k)

	r := combine(n-1, k-1)
	for i := 0; i < len(r); i++ {
		r[i] = append(r[i], n)
	}

	res = append(res, r...)

	return res
}
// @lc code=end

