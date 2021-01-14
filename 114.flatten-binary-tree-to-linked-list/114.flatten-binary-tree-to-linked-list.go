/*
 * @lc app=leetcode id=114 lang=golang
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (46.60%)
 * Likes:    2230
 * Dislikes: 275
 * Total Accepted:    304.6K
 * Total Submissions: 653.6K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
func flatten(root *TreeNode)  {
    if root != nil {
		r(root)
	}
}

func r(root *TreeNode) *TreeNode {
	if root.Left == nil && root.Right == nil {
		return root
	}

	right := root.Right

	if root.Left != nil {
		leftl := r(root.Left)
		if root.Right == nil {
			root.Left, root.Right = nil, root.Left
			return leftl
		}

		root.Left, root.Right = nil, root.Left
		leftl.Right = right
	}

	return r(right)
}
// @lc code=end

