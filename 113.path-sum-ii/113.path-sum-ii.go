/*
 * @lc app=leetcode id=113 lang=golang
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (44.46%)
 * Likes:    1375
 * Dislikes: 47
 * Total Accepted:    296.2K
 * Total Submissions: 666.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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
func pathSum(root *TreeNode, sum int) [][]int {
	var res [][]int
	if root != nil {
		r(root, sum, []int{}, &res)
	}

	return res
}

func r(root *TreeNode, sum int, path []int, res *[][]int) {
	sum -= root.Val
	path = append(path, root.Val)

	if root.Left == nil && root.Right == nil {
		if sum == 0 {
			*res = append(*res, path)
		}

		return
	}

	if root.Left != nil {
		p := make([]int, len(path))
		copy(p, path)
		r(root.Left, sum, p, res)
	}

	if root.Right != nil {
		p := make([]int, len(path))
		copy(p, path)
		r(root.Right, sum, p, res)
	}
}
// @lc code=end

