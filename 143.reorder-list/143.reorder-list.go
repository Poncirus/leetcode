/*
 * @lc app=leetcode id=143 lang=golang
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (34.52%)
 * Likes:    1453
 * Dislikes: 98
 * Total Accepted:    202.1K
 * Total Submissions: 584K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
func reorderList(head *ListNode)  {
	if head == nil || head.Next == nil {
		return
	}
	
	p, q := head, head.Next.Next

	for q != nil {
		for i := 0; i < 2 && q != nil; i++ {
			q = q.Next
		}

		p = p.Next
	}

	q = p.Next
	p.Next = nil
	p = q
	q = p.Next
	p.Next = nil
	for q != nil {
		t := q.Next
		q.Next = p
		p = q
		q = t
	}

	for p != nil {
		t := head.Next
		head.Next = p
		head = p
		p = t
	}
}
// @lc code=end

