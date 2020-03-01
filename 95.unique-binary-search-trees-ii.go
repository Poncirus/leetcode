/*
 * @lc app=leetcode id=95 lang=golang
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (38.50%)
 * Likes:    1760
 * Dislikes: 143
 * Total Accepted:    171.1K
 * Total Submissions: 443.8K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func generateTrees(n int) []*TreeNode {
	if n == 0 {
		return []*TreeNode{}
	}

	ns := make([]int, n)
	for i := 1; i <= n; i++ {
		ns[i-1] = i
	}

	return g(ns)
}

func g(nums []int) []*TreeNode {
	if len(nums) == 0 {
		return []*TreeNode{nil}
	}

	var res []*TreeNode
	for i, v := range(nums) {
		l := g(nums[:i])
		r := g(nums[i+1:])

		for _, ll := range(l) {
			for _, rr := range(r) {
				root := &TreeNode{v, ll, rr}
				res = append(res, root)
			}
		}
	}

	return res
}
// @lc code=end

