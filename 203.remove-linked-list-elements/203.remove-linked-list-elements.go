/*
 * @lc app=leetcode id=203 lang=golang
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (37.15%)
 * Likes:    1248
 * Dislikes: 73
 * Total Accepted:    290.2K
 * Total Submissions: 780.1K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
	h := &ListNode{0, head}
	for p := h; p != nil; p = p.Next {
		for p.Next != nil && p.Next.Val == val {
			p.Next = p.Next.Next
		}
	}

	return h.Next
}
// @lc code=end

