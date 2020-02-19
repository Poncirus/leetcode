/*
 * @lc app=leetcode id=46 lang=golang
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (59.90%)
 * Likes:    3041
 * Dislikes: 93
 * Total Accepted:    512K
 * Total Submissions: 851.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
func permute(nums []int) [][]int {
    return p(nums, []int{})
}

func p(nums []int, r []int) [][]int {
	if len(nums) == 0 {
		return [][]int{r}
	}
	
	res := [][]int{}

	for i, v := range(nums) {
		n := make([]int, len(nums)-1)
		copy(n, nums[:i])
		copy(n[i:], nums[i+1:])
		r := append(r, v)
		res = append(res, p(n, r)...)
	}

	return res
}
// @lc code=end

