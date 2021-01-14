/*
 * @lc app=leetcode id=90 lang=golang
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (45.25%)
 * Likes:    1346
 * Dislikes: 58
 * Total Accepted:    250.6K
 * Total Submissions: 553.4K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */

// @lc code=start
func subsetsWithDup(A []int) [][]int {
	res := [][]int{}
	sort.Ints(A)

	var dfs func(int, []int)
	dfs = func(index int, temp []int) {
		res = append(res, temp)
		n := len(temp) + 1
		for i := index; i < len(A); i++ {
			if i == index || A[i] != A[i-1] {
				dfs(i+1, append(temp, A[i])[:n:n])
			}
		}
	}

	temp := make([]int, 0, 0)
	dfs(0, temp)

	return res
}

// @lc code=end

