/*
 * @lc app=leetcode id=98 lang=golang
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (27.09%)
 * Likes:    3121
 * Dislikes: 447
 * Total Accepted:    585.2K
 * Total Submissions: 2.2M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
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
func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	b, _, _ := r(root)
	return b
}

func r(root *TreeNode) (bool, int, int) {
	min, max := root.Val, root.Val
	if root.Left != nil {
		var b bool
		var v int
		b, min, v = r(root.Left)
		if !b || v >= root.Val {
			return false, 0, 0
		}
	}

	if root.Right != nil {
		var b bool
		var v int
		b, v, max = r(root.Right)
		if !b || v <= root.Val {
			return false, 0, 0
		}
	}

	return true, min, max
}
// @lc code=end

