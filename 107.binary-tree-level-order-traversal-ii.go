/*
 * @lc app=leetcode id=107 lang=golang
 *
 * [107] Binary Tree Level Order Traversal II
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
func levelOrderBottom(root *TreeNode) [][]int {
	var res [][]int

	var addNode func(*TreeNode, int)
	addNode = func(r *TreeNode, i int) {
		if r == nil {
			return
		}

		if i > len(res) {
			res = append([][]int{[]int{}}, res...)
		}
		n := len(res)
		res[n-i] = append(res[n-i], r.Val)

		addNode(r.Left, i+1)
		addNode(r.Right, i+1)
	}

	addNode(root, 1)
	return res
}

// @lc code=end
