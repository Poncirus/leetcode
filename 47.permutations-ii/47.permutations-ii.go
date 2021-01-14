/*
 * @lc app=leetcode id=47 lang=golang
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (43.77%)
 * Likes:    1546
 * Dislikes: 56
 * Total Accepted:    309.8K
 * Total Submissions: 702.4K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */

// @lc code=start
import "sort"
func permuteUnique(nums []int) [][]int {
	sort.Ints(nums)
    return p(nums, []int{})
}

func p(nums []int, r []int) [][]int {
	if len(nums) == 0 {
		return [][]int{r}
	}
	
	res := [][]int{}

	first := true
	var l int
	for i, v := range(nums) {
		if !first && l == v {
			continue
		}

		first = false
		l = v

		n := make([]int, len(nums)-1)
		copy(n, nums[:i])
		copy(n[i:], nums[i+1:])
		nr := make([]int, len(r))
		copy(nr, r)
		nr = append(nr, v)
		res = append(res, p(n, nr)...)
	}

	return res
}
// @lc code=end

