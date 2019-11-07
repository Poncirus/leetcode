/*
 * @lc app=leetcode id=25 lang=golang
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (37.55%)
 * Likes:    1487
 * Dislikes: 299
 * Total Accepted:    215.6K
 * Total Submissions: 560.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 *
 *
 *
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
func reverseKGroup(head *ListNode, k int) *ListNode {
	m := make([](*ListNode), k)
	i := 0

	h := &ListNode{}
	r := h
	h.Next = head

	for h.Next != nil {
		t := h
		h = h.Next
		for i = 0; i < k && h != nil; i++ {
			m[i] = h
			h = h.Next
		}

		if i != k {
			break
		}

		i--

		m[0].Next = h
		h = m[0]
		t.Next = m[i]
		for ; i > 0; i-- {
			m[i].Next = m[i-1]
		}
	}

	return r.Next
}

// @lc code=end
