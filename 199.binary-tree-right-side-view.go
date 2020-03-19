/*
 * @lc app=leetcode id=199 lang=golang
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (51.75%)
 * Likes:    1741
 * Dislikes: 97
 * Total Accepted:    241K
 * Total Submissions: 464.7K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
func rightSideView(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	t := make([]*TreeNode, 0, 128)
	t = append(t, root)
	p := 1

	var res []int

	for p != 0 {
		res = append(res, t[0].Val)

		tp := 0
		for ; p > 0; p-- {
			if t[0].Right != nil {
				t = append(t, t[0].Right)
				tp++
			}

			if t[0].Left != nil {
				t = append(t, t[0].Left)
				tp++
			}

			t = t[1:]
		}
		p = tp
	}

	return res
}
// @lc code=end

