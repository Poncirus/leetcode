/*
 * @lc app=leetcode id=160 lang=golang
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	a, b := headA, headB
	hasLinkedToB, hasLinkedToA := false, false
	for a != nil && b != nil {
		if a == b {
			return b
		}
		a, b = a.Next, b.Next
		if a == nil && !hasLinkedToB {
			a = headB
			hasLinkedToB = true
		}
		if b == nil && !hasLinkedToA {
			b = headA
			hasLinkedToA = true
		}
	}
	return nil
}

// @lc code=end
