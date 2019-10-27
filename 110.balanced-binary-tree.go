/*
 * @lc app=leetcode id=110 lang=golang
 *
 * [110] Balanced Binary Tree
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
func isBalanced(root *TreeNode) bool {
	_, b := getDepth(root, 0)

	return b
}

func getDepth(r *TreeNode, d int) (int, bool) {
	if r == nil {
		return d, true
	}

	i, b1 := getDepth(r.Left, d+1)
	j, b2 := getDepth(r.Right, d+1)

	if !b1 || !b2 {
		return 0, false
	}

	if i > j && i-j < 2 {
		return i, true
	} else if j >= i && j-i < 2 {
		return j, true
	} else {
		return 0, false
	}
}

// @lc code=end
