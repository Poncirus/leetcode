/*
 * @lc app=leetcode id=24 lang=golang
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (45.94%)
 * Likes:    1495
 * Dislikes: 136
 * Total Accepted:    373.2K
 * Total Submissions: 794K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
func swapPairs(head *ListNode) *ListNode {
	h := &ListNode{}
	r := h
	h.Next = head

	for h.Next != nil && h.Next.Next != nil {
		i, j, k := h.Next, h.Next.Next, h.Next.Next.Next
		h.Next = j
		j.Next = i
		i.Next = k
		h = i
	}

	return r.Next
}

// @lc code=end
