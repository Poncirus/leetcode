/*
 * @lc app=leetcode id=21 lang=golang
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (48.11%)
 * Likes:    2455
 * Dislikes: 349
 * Total Accepted:    637.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 *
 *
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	r := new(ListNode)
	s := r
	for {
		if l1 == nil {
			s.Next = l2
			break
		}

		if l2 == nil {
			s.Next = l1
			break
		}

		if l1.Val < l2.Val {
			s.Next = l1
			l1 = l1.Next
			s = s.Next
		} else {
			s.Next = l2
			l2 = l2.Next
			s = s.Next
		}
	}

	return r.Next
}
