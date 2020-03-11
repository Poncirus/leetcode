/*
 * @lc app=leetcode id=124 lang=golang
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (32.38%)
 * Likes:    2655
 * Dislikes: 216
 * Total Accepted:    279.7K
 * Total Submissions: 863.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * Output: 42
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
func maxPathSum(root *TreeNode) int {
	res := root.Val;

	rv := root.Val;

	if root.Left != nil {
		t := maxPathSum(root.Left)
		rv += maxRoot(root.Left)
		if t > res {
			res = t
		}
	}

	if root.Right != nil {
		t := maxPathSum(root.Right)
		rv += maxRoot(root.Right)
		if t > res {
			res = t
		}
	}

	if rv > res {
		res = rv
	}

	return res
}

func maxRoot(root *TreeNode) int {
	res := 0;

	if root.Left != nil {
		l := maxRoot(root.Left) + root.Val
		if l > res {
			res = l
		}
	}

	if root.Right != nil {
		r := maxRoot(root.Right) + root.Val
		if r > res {
			res = r
		}
	}

	if root.Val > res {
		res = root.Val
	}

	return res
}
// @lc code=end

