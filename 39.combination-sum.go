/*
 * @lc app=leetcode id=39 lang=golang
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (52.69%)
 * Likes:    2966
 * Dislikes: 93
 * Total Accepted:    459.5K
 * Total Submissions: 865.6K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */

// @lc code=start
func combinationSum(candidates []int, target int) [][]int {
	dp := make([][][]int, target+1)
	for _, v := range candidates {
		if v <= target {
			dp[v] = append(dp[v], []int{v})
		}
	}

	for i := 1; i <= target; i++ {
		for _, v := range candidates {
			if i-v < 0 {
				continue
			}

			for _, f := range dp[i-v] {
				if v >= f[len(f)-1] {
					ns := make([]int, len(f), len(f)+1)
					copy(ns, f)
					dp[i] = append(dp[i], append(ns, v))
				}
			}
		}
	}

	return dp[target]
}

// @lc code=end
