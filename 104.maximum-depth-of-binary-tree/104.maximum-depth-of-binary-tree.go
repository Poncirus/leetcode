/*
 * @lc app=leetcode id=104 lang=golang
 *
 * [104] Maximum Depth of Binary Tree
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
func maxDepth(root *TreeNode) int {
	return getDepth(root, 0)
}

func getDepth(r *TreeNode, d int) int {
	if r == nil {
		return d
	}

	i := getDepth(r.Left, d+1)
	j := getDepth(r.Right, d+1)

	if i > j {
		return i
	} else {
		return j
	}
}

// @lc code=end
