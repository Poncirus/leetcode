/*
 * @lc app=leetcode id=112 lang=golang
 *
 * [112] Path Sum
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
func hasPathSum(root *TreeNode, sum int) bool {
	if root == nil {
		return false
	}

	sum -= root.Val
	if sum == 0 && root.Left == nil && root.Right == nil {
		return true
	}

	return hasPathSum(root.Left, sum) || hasPathSum(root.Right, sum)
}

// @lc code=end
